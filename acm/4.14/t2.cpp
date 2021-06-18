#include<iostream>
#include<queue>
#include<stdio.h>

using namespace std;

queue<int> q;
queue<int> thrown;

int main() {
    int num;
    cout << "输入： ";
    cin >> num;

    for (int i = 1; i <= num; i++) {
        q.push(i);
    }

    cout << "输出： "; 
    while(q.size() >= 2) {
        cout << q.front() << " ";
        q.pop();
        int anthor = q.front();
        q.pop();
        q.push(anthor);
    }
    cout << q.front() << " ";
}