#include<iostream>

using namespace std;



int main() {
    int count[10];
    bool flag;
    for (int i = 123; 3 * i <= 987; i++) {
        for(int m = 0; m <= 9; m++) {
            count[m] = 0;
        }
        int j, k;
        j = 2 * i;
        k = 3 * i;
        flag = false;

        count[i%10]++;
        count[j%10]++;
        count[k%10]++;

        count[i%100/10]++;
        count[j%100/10]++;
        count[k%100/10]++;

        count[i/100]++;
        count[j/100]++;
        count[k/100]++;
        if (count[0] != 0) continue;
        for (int m = 1; m <= 9; m++) {
            if (count[m] != 1) {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        cout << i << " " << j << " " << k << endl;
    }
}