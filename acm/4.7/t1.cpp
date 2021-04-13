#include<iostream>
#include<fstream>
#include<cstring>
#include<stack>
#include<climits>
#include<vector>

using namespace std;

vector<int> sum;

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TNode, Root;

typedef struct Data {
    int value;
    string str;
} Data;

typedef string Res;

// change the original to a target num and a string that present a tree
Data first_handle(string str) {
    Data data;
    int i = 0;
    while(str[i] != '(') {
        i++;
    }
    string number(str, 0, i);
    int target = atoi(number.c_str());
    data.value = target;
    // 一共有 len 个字符，前面 i 个数字不要，还有前后一对括号不要
    string words(str, i+1, str.size()-i-2);
    if (words.size() == 0) {
        data.str = "";
    } else {
        data.str = words;
    }
    return data;
}

// according to the structure of str, create node for Btree.
void createBTree(string str, Root *root) {
    stack<char> s;

    if (str.size() == 0) {
        root = NULL;
        return;
    }

    // get value
    int i = 0;
    while(str[i] != '(') {
        i++;
    }
    string number(str, 0, i);
    int value = atoi(number.c_str());
    root->value = value;

    string str_under_handle(str, i, str.size()-i);
    // get left string
    i = 1;
    s.push(str_under_handle[0]);
    while (!s.empty()) {
        switch(str_under_handle[i]) {
            case ')': 
                s.pop();
                break;
            case '(':
                s.push(str_under_handle[i]);
                break;
            default :
                break;
        }
        i++;
    }

    string left_part(str_under_handle, 1, i-1);
    string right_part(str_under_handle, i+1, str_under_handle.size()-i-2);

    if (left_part.size() > 2) {
        root->left = new TreeNode;
        createBTree(left_part, root->left);
    } else {
        root->left = NULL;
    }

    if (right_part.size() > 2) {
        root->right = new TreeNode;
        createBTree(right_part, root->right);
    } else {
        root->right = NULL;
    }
}

// get all paths' sum, and put them into vector sum.
void sumTree(Root *root, int value) {
    if (root == NULL || root->value == INT_MAX) {
        sum.insert(sum.end(), value);
        return;
    }

    sumTree(root->left, root->value+value);
    sumTree(root->right, root->value+value);
}

// format the content 
string format(string content) {
    // 实现了每一行的内容都紧凑地表示一颗树和目标数，并在末尾都能识别到一个'\n'
    int i = 0;
    string str;
    while(i < content.size()) {
        if (i < content.size()-1 && content[i] == '\n' && content[i+1] == '(') {
            i++;
            continue;
        }
        str += content[i];
        i++;
    }

    // return str;
    return str+'\n';
}

// judge whether the vector has the target number
Res solution(int target) {
    for (int i = 0; i < sum.size(); i++) {
        if (sum[i] == target) {
            return "yes";
        }
    }
    return "no";
}


// 核心思想：
// 1、对文件读取的同时对数据一并进行处理比较困难，转而存入string类型的数据后，再进行数据操作
// 2、对string类型的数据进行格式化，便于后续调度处理
// 3、根据传入的特点，先将字符串分割成 target 和 欲转换为树的字符串
// 4、根据欲转换为树的字符串结构特点，将字符串转换成树结构
// 5、利用vector储存所有根到叶子节点路径上值的总和，再进行判断，每次循环都清空vector的已有内容
int main() {
    // 把文件内的内容传送到 s 中
    fstream read;
    string content;
    string str;
    char *c = new char[1024];
    read.open("t1.txt",ios::in);
    if (!read.is_open()) {
        cout << "文件打开失败" << endl;
        return 0;
    }
    while ((*c = read.get()) != EOF) {
        if (*c != ' ') {
            content += *c;
        }
        c++;
    }
    read.close();

    // fisrt format
    str = format(content);

    int i = 0;
    int end, start = 0;
    while(i < str.size()) {
        if (str[i] != '\n') {
            i++;
            continue;
        }
        // the situation when the character come to '\n'
        end = i;
        // init sentence
        string sentence(str, start, end-start);
        // cout << "(" << start << "," << end << ")"  << sentence.size() << endl;
        // cout << sentence << endl;
        start = end + 1;
        i++;

        // now have gotten the single sentence 
        // let's change the sentence to a tree and a target number
        Data data = first_handle(sentence);

        Root *root = new Root;
        root->value = INT_MAX; // 标记，排除特殊情况
        root->left = NULL;
        root->right = NULL;;

        createBTree(data.str ,root);
        sumTree(root, 0);
        cout << solution(data.value) << endl;
        sum.clear();
    }
}