#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        long long int x, y;
        cin >> x >> y;
        if(__gcd(x, y) > 1) {
            cout << 0 << endl;
        }
        else {
            if(x % 2 == 1 || y % 2 == 1) {
                if(__gcd(x+1, y) > 1 || __gcd(x, y+1)) {
                    cout << 1 << endl;
                }
                else {
                    cout << 2 << endl;
                }
            }
            else {
                cout << 1 << endl;
            }
        }
    }
    return 0;
}
