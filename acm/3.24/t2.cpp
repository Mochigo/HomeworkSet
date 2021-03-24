#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

int main() {
    int num;

    for (int i = 11; i <= 99; i += 11) {
        for (int j = 0; j <= 9; j++) {
            num = i * 100 + j * 11;
            if (sqrt(num) == int(sqrt(num))) {
                cout << num << endl;
            }
        }
    }

}