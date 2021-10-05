#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int arr[], int n) {
    multi_map<int, int> mp;
    vector<int> v(n, 0);
    for(int i=0; i<n; i++) {
        mp.insert(pair<int, int> (arr[i], i));
    }
    for(auto it = mp.begin(); it != mp.end(); it++) {
        
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    vector<int> v = solve(arr, n);
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}