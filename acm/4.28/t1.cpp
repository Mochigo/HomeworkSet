#include <iostream>
#include <string>

using namespace std;

#define MAX 200

int main()
{
    int c1[MAX];
    int c2[MAX];
    int sum[MAX + 1];
    string t1, t2;
    string res;
    char c;
    cout << "整数1：";
    cin >> t1;
    cout << "整数2：";
    cin >> t2;

    for (int i = 0; i < MAX; i++) {
        sum[i] = 0;
        if (i < t1.size()) {
            c1[i] = t1[t1.size() - i - 1] - '0';
        } else {
            c1[i] = 0;
        }
    }

    for (int i = 0; i < MAX; i++) {
        if (i < t2.size()) {
            c2[i] = t2[t2.size() - 1 - i] - '0';
        } else {
            c2[i] = 0;
        }
    }

    sum[MAX] = 0;

    for (int i = 0; i < MAX; i++) {
        int tmp = c1[i] + c2[i] + sum[i];
        sum[i] = tmp % 10;
        sum[i + 1] = tmp / 10;
    }

    for (int i = MAX - 1; i >= 0; i--) {
        c = '0' + sum[i];
        res += c;
    }

    int j = 0;
    while (res[j] == '0') {
        j++;
    }

    string ret(res, j, MAX - j + 1);

    cout << ret << endl;
}