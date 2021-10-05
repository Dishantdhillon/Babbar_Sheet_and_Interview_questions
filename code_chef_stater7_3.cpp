#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        long long int n, k;
        cin >> n >> k;
        if(k == 0) {
            cout << 0 << endl;
        }
        else {
            if(k >= pow(2, n-1)) {
                long long int out = 2 * (pow(2, n) - 1) * pow(2, n-1);
                cout << out << endl;
            }
            else {
                long long int out = (pow(2, n) - 1);
                out = out * 2 * k;
                cout << out << endl;
            }
        }
    }
    return 0;
}
