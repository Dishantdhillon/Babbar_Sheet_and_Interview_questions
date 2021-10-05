#include<bits/stdc++.h>
using namespace std;

long int max(long int a, long int b) {
    if(a > b) {
        return a;
    }
    return b;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        long int arrP[n], arrS[n];
        for(int i=0; i<n; i++) {
            cin >> arrP[i];
        }
        for(int i=0; i<n; i++) {
            cin >> arrS[i];
        }
        map<long int, long int> mp;
        for(int i=0; i<n; i++) {
            mp[arrP[i]] = arrS[i];
        }
        auto left = mp.begin();
        auto right = mp.end();
        right--;
        int out = 0;
        while(*(left) < *(right)) {
            if(left->first + right->first > d) {
                right--;
            }
            else if(left->first + right->first  < d) {
                out = max(out, left->first + right->first);
                left++;
            }
            else {
                out = max(out, left->first + right->first);
                left++;
                right--;
            }
        }
        cout << out << endl;
    }
    return 0;
}