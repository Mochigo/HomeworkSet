#include <iostream>
#include <vector>

#define MAX 255

using namespace std;

vector<string> solution(int k)
{
    vector<string> res;
    for (int y = k + 1; y <= 2 * k; y++) {
        for (int x = y; x <= k + k*x/y +1; x++) {
            if (x * y == k * x + k * y) {
                char* s = new char[MAX];
                sprintf(s, "1/%d=1/%d+1/%d", k, x, y);
                res.push_back(s);
            }
        }
    }

    return res;
};

int main()
{
    vector<int> ns;
    int num;

    while (cin >> num) {
        ns.push_back(num);
        if (cin.eof()) {
            break;
        }
    }

    for (int i = 0; i < ns.size(); i++) {
        vector<string> tmp;
        tmp = solution(ns[i]);
        cout << tmp.size() << endl;
        for (auto i : tmp) {
            cout << i << endl;
        }
    }

    return 0;
}