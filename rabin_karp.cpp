#include<bits/stdc++.h>
using namespace std;

void rabin_karp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int q = 101, p = 0, t = 0, h = 1, d = 256;
    for(int i=0; i<m-1; i++) {
        h = (h*d) % q;
    }
    for(int i=0; i<m; i++) {
        t = (d*t + text[i]) % q;
        p = (d*p + pattern[i]) % q;
    }
    for(int i=m; i<n; i++) {
        if(t == p) {
            for(int j=i-m; j<i; j++) {
                if(text[j] != pattern[j-i+m]) {
                    break;
                }
                if(j == i-1) {
                    cout << "Pattern found at index " << i-m << "\n";
                }
            }
        }
        if(i < n) {
            t = (d*(t - text[i-m]*h) + text[i]) % q;
            if(t < 0) {
                t = t + q;
            }
        }
    }
}

int main() {
    string text, pattern;
    cin >> text;
    cin >> pattern;
    rabin_karp(text, pattern);
    return 0;
}
