#include <cmath>
#include <iostream>

using namespace std;

bool judge(int m)
{
    for (int i = 2; i <= sqrt(m) + 1; i++) {
        if (m % i == 0) {
            return false;
        }
    }
    return true;
}

void solution(int m)
{
    int i = m;
    while (1) {
        if (judge(i) && judge(i + 2)) {
            break;
        }
        i++;
    }
    cout << i << " " << i + 2 << endl;
}

int main()
{
    int m;
    cin >> m;
    if (m < 5 || m > 10000) {
        cout << "不在限定范围，请输入一个[5,10000]内的数字" << endl;
    }
    solution(m);
}