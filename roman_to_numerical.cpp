#include<bits/stdc++.h>
using namespace std;

int num(char s) {
    if(s == 'I') {
        return 1;
    }
    if(s == 'V') {
        return 5;
    }
    if(s == 'X') {
        return 10;
    }
    if(s == 'L') {
        return 50;
    }
    if(s == 'C') {
        return 100;
    }
    if(s == 'D') {
        return 500;
    }
    if(s == 'M') {
        return 1000;
    }
}

int romanToDecimal(string &str) {
    int n = str.length();
    int sum = num(str[n-1]);
    for(int i = n-2; i >= 0; i--) {
        if(num(str[i]) < num(str[i+1])) {
            sum = sum - num(str[i]);
        }
        else {
            sum = sum + num(str[i]);
        }
    }
    return sum;
}

int main() {
    string s;
    cin >> s;
    cout << romanToDecimal(s);
}
