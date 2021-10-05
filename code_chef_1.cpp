#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int x, y, z, d;
        cin >> d >> x >> y >> z;
        cout << max(7*x, d*y + (7-d)*z) << endl;
    }
    return 0;
}