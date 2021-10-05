#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        if(k >= n) {
            cout << n << endl;
        }
        else {
            unordered_map<int, int> mp;
            for(int i=0; i<n; i++) {
                mp[arr[i]]++;
            }
            int cnt = -1;
            for(auto it -> mp.begin(); it != mp.end(); it++) {
                cnt = max(cnt, it -> second);
            }
            if(cnt + k >= n) {
                cout << n << endl;
            }
            else {
                cout << cnt + k << endl;
            }
        }
    }
    return 0;
}
