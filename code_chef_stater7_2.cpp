#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long int e, k;
        cin >> e >> k;
        int ans = 0;
        if(e == 0) {
            cout << 0 << endl;
        }
        else {
            while(e > 0) {
                e = e/k;
                ans = ans + 1;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
