#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // a, b, c 分别表示百十个位
    int a, b, c; 
    double sum;
    for (int i = 100; i <= 999; i++) {
        a = i / 100;
        b = i % 100 / 10;
        c = i % 10;
        sum = pow(double(a), 3) + pow(double(b), 3) + pow(double(c), 3);
        if (sum == i) {
            cout << i << endl;
        }
    }
}