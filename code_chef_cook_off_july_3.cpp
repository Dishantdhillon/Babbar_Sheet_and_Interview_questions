#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[arr[i]]++;
        }
        long int sum = 0;
        for(auto: it = mp.begin(); it != mp.end(); it++) {
            if(it -> second >= it -> first) {
                sum += it -> first - 1;
            }
            else {
                sum += it -> second - 1;
            }
        }
    }
    return 0;
}
