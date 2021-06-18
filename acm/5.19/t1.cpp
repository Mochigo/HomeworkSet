#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set> // 去重
#include <vector>

using namespace std;

map<char, int> m;
map<char, vector<char>> more;
map<char, char> relation;

int compare(const char& a, const char& b)
{
    return m[a] > m[b];
}

int main()
{
    fstream read;
    read.open("data.txt", ios::in);
    if (!read.is_open()) {
        cout << "文件未正常打开" << endl;
        return (0);
    }

    int A, K;
    read >> A >> K;
    if (A < 0 && A > 26) {
        cout << "A 值非法输入，A值应为[1，26]" << endl;
        return (0);
    }
    string* s = new string[K];
    for (int i = 0; i < K; i++) {
        read >> s[i];
    }
    string str;
    read >> str;
    read.close();

    // 获取所有的字母
    int count = A;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < s[i].size(); j++) {
            if (m[s[i][j]] == 0) {
                m[s[i][j]] = 1;
                count--;
            }
            if (count == 0) {
                break;
            }
        }
        if (count == 0) {
            break;
        }
    }

    // 根据输入，获得未处理的大小关系
    for (int i = 0; i < K - 1; i++) {
        int j = i + 1;
        int index = 0;
        // 当出现了第一个不同的字母的时候退出循环
        while (s[i][index] == s[j][index]) {
            index++;
        }
        more[s[i][index]].push_back(s[j][index]);
    }

    for (auto& it : m) {
        // 从 m 中 获取所有字母的可能性， c代表字母，lists代表对应字母的 大小关系
        char c = it.first;
        vector<char> lists = more[c];

        while (lists.size() > 0) {
            vector<char> tmp;
            for (int i = 0; i < lists.size(); i++) {
                char ch = lists[i];
                if (more[ch].size() > 0) {
                    for (int i = 0; i < more[ch].size(); i++) {
                        tmp.push_back(more[ch][i]);
                        more[c].push_back(more[ch][i]);
                    }
                }
            }
            lists = tmp;
        }
    }

    vector<char> current;
    vector<char> previous;
    // 去重
    for (auto& it : more) {
        char c = it.first;
        current.push_back(c);
        previous.push_back(c);
        vector<char> lists = more[c];

        set<char> un(lists.begin(), lists.end());
        more[c].assign(un.begin(), un.end());
        m[c] = more[c].size() + 1; // 统计优先级
    }

    sort(previous.begin(), previous.end());
    sort(current.begin(), current.end(), compare); // 排序算法
    for (int i = 0; i < current.size(); i++) {
        relation[current[i]] = previous[i]; // 建立对应关系
    }

    string res = "";
    for (int i = 0; i < str.size(); i++) {
        res += relation[str[i]];
    } 

    cout << res << endl;
}