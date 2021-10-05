#include<bits/stdc++.h>
using namespace std;

transform(string a, string b) {
    int n1 = a.length();
    int n2 = b.length();
    if(n1 != n2) {
        return -1;
    }
    
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << transform(a, b);
    return 0;
}