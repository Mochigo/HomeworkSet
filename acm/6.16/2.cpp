#include <iostream>
#include <sstream>

using namespace std;

#define MAX 1000

string big_num_add(string t1, string t2);

string removeZero(string res) {
    int j = 0;
    while (res[j] == '0') {
        j++;
    }

    string ret(res, j, MAX - j + 1);

    return ret;
}

// 相当于两个整数相加
string f(int n, int m, int times)
{
    if (times == m-1) {
        // 因为m <= n <= 10^6; 所以n-m+1的值 并没有溢出，这里选择使用itoa的函数进行转化
        string tmp = to_string(n+times-m+1);
        return tmp;
    }
    string target = f(n - 1, m, times+1); 
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

    string tmp = removeZero(res);
    if (tmp.length() <= 6) {
        return tmp;
    }
    string ans(tmp, tmp.length()-6, 6);

    return removeZero(ans);
}

int main()
{
    int n, m;
    cin >> m >> n;
    cout << f(n, m, 0);
}