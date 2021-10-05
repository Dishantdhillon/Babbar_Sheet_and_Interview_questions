#include<bits/stdc++.h>
using namespace std;

bool simplePath(int arrT[], int n, int arrQ[], int k) {
    if(k <= 2) {
        return true;
    }
    
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        unordered_set<int> set;
        int arr[n];
        for(int i=0; i<n-1; i++) {
            int a, b;
            cin >> a >> b;
            if(set.find(b) == set.end()) {
                set.insert(b);
            }
            if(set.find(a) == set.end()) {
                set.insert(a);
            }
        }
        int j = n-1;
        for(auto it = set.begin(); it != set.end(); it++, j--) {
            arr[j] = *it;
        }
        int q;
        cin >> q;
        for(int i=0; i<q; i++) {
            int k;
            cin >> k;
            int arr1[k];
            for(int i=0; i<k; i++) {
                cin >> arr1[k];
            }
            if(simplePath(arr, n, arr1, k)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}