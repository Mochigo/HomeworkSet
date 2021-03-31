#include<iostream>
#include<fstream>

#define M "is a mirrored string."
#define MP "is a mirrored palindrome."
#define NP "is not a palindrome."
#define P "is a regular palindrome."

using namespace std;

char change(char c) {
    switch(c) {
        case 'E': return '3'; break;
        case 'J': return 'L'; break;
        case 'S': return '2'; break;
        case 'Z': return '5'; break;
        case '2': return 'S'; break;
        case '3': return 'E'; break;
        case '5': return 'Z'; break;

        case 'A':
        case 'T':
        case 'H':
        case 'M':
        case 'O':
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case '1':
        case '8':  return c; break;

        case 'B': 
        case 'C':
        case 'D':
        case 'F':
        case 'G':
        case 'K':
        case 'N':
        case 'P':
        case 'Q':
        case 'R':
        case '4':
        case '6': 
        case '7':
        case '9': 
        default: return ' '; break;
    }
}

string solution(string s) {
    bool ip = true, im = true;
    int len = s.size();
    for (int i = 0; i < len/2; i++) {
        if (s[i] != s[len-i-1]) {
            ip = false;
            break;
        }
    }
    for (int i = 0; i < len/2; i++) {
        if (change(s[len-i-1]) == ' ' || change(s[i]) == ' ' || s[i] != change(s[len-i-1])) {
            im = false;
            break;
        }
    }
    if (ip && im) {
        return MP;
    } else if (!ip && im) {
        return M;
    } else if (ip && !im) {
        return P;
    } else {
        return NP;
    }
}

int main() {
    fstream read;

    read.open("t2.txt", ios::in);
    string str;
    while(getline(read, str)) {
        cout << str << " -- " << solution(str) << endl; 
    }

    read.close();
}