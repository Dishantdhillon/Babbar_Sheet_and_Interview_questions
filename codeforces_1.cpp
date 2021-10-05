#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        long long int a, b;
        cin >> a >> b;
        if(a == b) {
            cout << 0 << " " << 0 << endl;
            continue;
        }
        long long int g = abs(a - b);
        int mi = min(a%g, g-(a%g));
        cout << abs(a - b) << " " << mi << endl;
    }
    return 0;
}
