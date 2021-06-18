#include<iostream>
#include<cmath>
#include<queue>

using namespace std;

// 分配编号
int count = 1;

typedef struct TreeNode {
    int no;
    bool on;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode, *Root;

queue<TreeNode*> q;

void initNode(TreeNode *node) {
    node->no = count;
    count++;
    node->left = NULL;
    node->right = NULL;
    node->on = false;
}

void printTree(Root root) {
    if (root == NULL) {
        return;
    }

    cout << root->no << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    int target_depth, num;
    cout << "样例输入： ";
    cin >> target_depth >> num;
    
    if (target_depth > 20 || target_depth < 0) {
        cout << "深度不符合要求" << endl;
        return 0; 
    }

    // 初始化根节点
    int cur_depth = 1;
    Root root;
    root = new TreeNode;
    initNode(root);

    // 生成树，由于编号问题，这里选择使用层次遍历
    q.push(root);
    while(true) {
        cur_depth ++;
        if (cur_depth > target_depth) {
            break;
        }
        int times = q.size();
        for (int i = 1; i <= times; i++) {
            TreeNode *node;
            node = q.front();
            q.pop();

            node->left = new TreeNode;
            initNode(node->left);
            node->right = new TreeNode;
            initNode(node->right);

            q.push(node->left);
            q.push(node->right);
        }
    }

    // 扔球
    int i = 1; 
    int final_pos = 0;
    while(i <= num) {
        TreeNode *pos;
        pos = root;
        while (pos->left != NULL || pos->right != NULL) {
            if (pos->on) {
                pos->on = false;
                pos = pos->right;
            } else {
                pos->on = true;
                pos = pos->left;
            }
        }
        final_pos = pos->no;
        i++;
    }
    
    cout << "样例输出： " << final_pos << endl;
}