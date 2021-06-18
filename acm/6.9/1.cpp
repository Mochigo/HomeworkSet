#include <iostream>
#include <vector>

using namespace std;

bool judge(int a, int b)
{
    int c[10] = { 0 };
    while (a != 0) {
        c[a % 10]++;
        a /= 10;
    }
    while (b != 0) {
        c[b % 10]++;
        b /= 10;
    }

    for (int i = 1; i < 10; i++) {
        if (c[i] != 1) {
            return false;
        }
    }

    return true;
}

void solution(int n)
{
    int max = 98765 / n + 1;
    for (int a = 1234; a <= max; a++) {
        int b = a * n;
        if (judge(a, b)) {
            string str_a, str_b;
            str_a = to_string(a);
            str_b = to_string(b);
            if (a >= 1000 && a < 10000) {
                str_a = "0" + str_a;
            }
            cout << str_b << "/" << str_a << "=" << n << endl;
        }
    }

};


int main()
{
    int n;
    cin >> n;

    if (n < 2 || n > 79) {
        cout << "n输入不符合规定，请输入一个数∈[2,79]" << endl;
        return 0;
    }

    solution(n);
}