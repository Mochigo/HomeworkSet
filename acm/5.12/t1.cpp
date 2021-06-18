#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<char, vector<int>> m;
map<char, int> res;

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Picture {
    int min_x;
    int max_x;
    int min_y;
    int max_y;
} Picture;

void deleteTarget(int t)
{
    for (auto& it : m) {
        // cout << it.first << "-";
        for (vector<int>::iterator iter = it.second.begin(); iter != it.second.end();) {
            // cout << (*iter) << " ";
            if ((*iter) == t) {
                // cout << "删除了 " << (*iter) << endl;
                iter = it.second.erase(iter);
            } else {
                iter++;
            }
        }
        // cout << endl;
    }
}

int main()
{
    fstream read;
    string input = "Slides.txt";
    read.open(input, ios::in);
    if (!read.is_open()) {
        cout << "打开" << input << "失败" << endl;
        return 0;
    }

    int total;
    read >> total;
    Point* points = new Point[total + 1];
    Picture* pictures = new Picture[total + 1];

    for (int i = 0; i < total; i++) {
        char c = i + 65;
        read >> pictures[i + 1].min_x;
        read >> pictures[i + 1].max_x;
        read >> pictures[i + 1].min_y;
        read >> pictures[i + 1].max_y;
        //cout << c << " (" << pictures[i + 1].min_x << "," << pictures[i + 1].max_x
        //<< "," << pictures[i + 1].min_y << "," << pictures[i + 1].max_y << ")" << endl;
    }

    for (int i = 0; i < total; i++) {
        read >> points[i + 1].x;
        read >> points[i + 1].y;
        //cout << i + 1 << " (" << points[i + 1].x << ", " << points[i + 1].y << ")" << endl;
    }
    read.close();

    // 循环，将每张图片有可能对应的数字编号全部存储。
    for (int i = 1; i <= total; i++) {
        for (int j = 1; j <= total; j++) {
            if (points[j].x <= pictures[i].max_x && points[j].x >= pictures[i].min_x
                && points[j].y <= pictures[i].max_y && points[j].y >= pictures[i].min_y) {
                m[64 + i].push_back(j);
            }
        }
    }

    for (auto& it : m) {
        cout << it.first << "-";
        for (int i = 0; i < it.second.size(); i++) {
            cout << it.second[i] << " ";
        }
        cout << endl;
    }

    fstream write;
    write.open("Slides_out.txt", ios::out);
    if (!write.is_open()) {
        cout << "写失败" << endl;
        return 0;
    }

    // 循环，寻找图片对应的数字编号只有一张的情况
    int count = total;
    while (m.size() != 0) {
        // 恰巧的话，每次会删除一个
        char c;
        bool flag = false; // 用来标记，每次都确实地找到了只存在一种对应关系的图片-数字
        for (auto& it : m) {
            c = it.first;
            if (it.second.size() == 1) {
                flag = true;
                res[c] = it.second[0];
                // cout << "找到了" << it.first << "-" << it.second[0] << endl;
                // 把别人中出现的删除
                deleteTarget(it.second[0]);
                count--;
                break;
            }
        }
        // 把字母删除
        m.erase(c);
        // 如果没找到，
        if (!flag) {
            write << "None";
            return 0;
        }
    }

    for (auto& it : res) {
        write << it.first << " " << it.second << endl;
    }
    write.close();

    return 0;
}