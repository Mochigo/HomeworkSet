#include<iostream>
#include<fstream>
#include<stack>

#define No "No"
#define Yes "Yes"

using namespace std;

stack<char> s;

string solution(string str) {
    while (!s.empty()) {
        s.pop();
    }
    int len = str.size();
    for (int i = 0; i < len; i++) {
        switch (str[i]) {
            case '(' :
            case '[' : 
                s.push(str[i]); break;
            case ')' : 
                if (s.empty() || s.top() != '(') {
                    return No;
                }
                s.pop();
                break;
            case ']' :
                if (s.empty() || s.top() != '[') {
                    return No;
                }
                s.pop();
                break;
        }
    }
    if (s.empty()) {
        return Yes;
    }
    return No;
}

int main() {
    int num;
    fstream read;
    string *str;

    read.open("data.txt",ios::in);
    if (!read.is_open()) {
        return 0;
    }

    read >> num;

    str = new string[num];
    for (int i = 0; i < num; i++) {
        read >> str[i];
    }

    // 遍历字符串
    for (int i = 0; i < num; i++) {
        cout << solution(str[i]) << endl;
    }

    delete[] str;
    read.close();
}