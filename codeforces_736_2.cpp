#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int count = 0;
        for(int i=0; i<n; i++) {
            if(int(a[i])-48 == 0 && int(b[i])-48 == 1) {
                count++;
            }
            else if(int(a[i])-48 == 1 && int(b[i])-48 == 1) {
                if(int(a[i-1])-48 == 1) {
                    a[i-1] = '0';
                    count++;
                }
                else if(int(a[i+1])-48 == 1) {
                    a[i+1] = '0';
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
