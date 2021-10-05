#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string str;
        cin >> str;
        int n = str.length();
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum = sum + int(str[i]) - 96;
        }
        if(sum == (n*(n+1))/2) {
        	
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
