#include <iostream>

using namespace std;

int solution(int n, int m)
{
    bool* left = new bool[n + 1];
    // 初始化数组，每个值都为true
    for (int i = 1; i <= n; i++) {
        left[i] = true;
    }

    // count记录还剩下的猴子数
    int count = n - 1;
    int j = 0;
    for (int i = 1; i <= n - 1; i++) {
        int k = m;
        j = j + 1;
        while (1) {
            if (j == n + 1) {
                j = 1;
            }
            // monkey存在报数
            if (left[j]) {
                k--;
            }
            if (k == 0) {
                left[j] = false;
                break;
            }
            j++;
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (left[i]) {
            res = i;
            break;
        }
    }

    delete[] left;

    return res;
}

int main()
{
    int n[1000], m[1000];
    int i = 0;
    cout << "输入样例：" << endl;
    while (1) {
        cin >> n[i] >> m[i];
        if (n[i] == 0 && m[i] == 0) {
            break;
        }
        i++;
    }

    cout << "输出样例: " << endl;
    for (int j = 0; j < i; j++) {
        cout << solution(n[j], m[j]) << endl;
    }
}