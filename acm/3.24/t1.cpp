#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int num;

    cout << "请输入一个2~100范围内的正整数:";
    cin >> num;

    for (int a = 2; a <= num; a++) {
        for (int b = 2; b < a; b++) {
            for (int c = b; c < a; c++) {
                for (int d = c; d < a; d++) {
                    if (pow(double(a), 3) == pow(double(b), 3)+pow(double(c), 3)+pow(double(d), 3)) {
                        cout << "Cube=" << a << "，triple=(" << b << "," << c << "," << d << ")"  << endl;
                    }
                }
            }
        }
    }
}