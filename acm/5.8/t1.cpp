#include <iostream>
#include <sstream>

using namespace std;

#define MAX 1000

string big_num_add(string t1, string t2);

// 相当于两个整数相加
string f(int n)
{
    if (n == 1) {
        return "1";
    }
    string target = f(n - 1);
    string res = "0";
    // 相加 n 次
    for (int i = 1; i <= n; i++) {
        res = big_num_add(res, target);
    }
    return res;
}

// 实现两个大整数相加
string big_num_add(string t1, string t2)
{
    int c1[MAX];
    int c2[MAX];
    int sum[MAX + 1];
    string res;
    char c;

    // 将每一位存放到数组中
    for (int i = 0; i < MAX; i++) {
        // 这里对sum数组进行初始化
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
        sum[i + 1] = sum[i + 1] + tmp / 10;
    }

    for (int i = MAX; i >= 0; i--) {
        c = '0' + sum[i];
        res += c;
    }

    int j = 0;
    while (res[j] == '0') {
        j++;
    }

    string ret(res, j, MAX - j + 1);

    return ret;
}

int main()
{
    int n;
    cin >> n;
    cout << f(n);
}