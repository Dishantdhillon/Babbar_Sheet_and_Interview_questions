#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[arr[i]]++;
        }
        long int sum = n * (n-1);
        for(auto it = mp.begin(); it != mp.end(); it++) {
            sum -= (it -> second() * it -> second - 1);
        }
        cout << sum << endl;
    }
    return 0;
}