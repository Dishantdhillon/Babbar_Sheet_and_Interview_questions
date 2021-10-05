#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int sum = 0, count = 0;
        for(int i=0; i<n; i++) {
            sum = sum + int(str[i]) - 48;
        }
        for(int i=0; i<n; i++) {
            if(int(str[i]) > 48) {
                count++;
            }
        }
        if(int(str[n-1]) == 48) {
            cout << sum + count << endl;
        }
        else {
            cout << sum + count - 1 << endl;
        }
    }
    return 0;
}
