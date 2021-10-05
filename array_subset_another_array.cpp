#include<bits/stdc++.h>
using namespace std;

/*int binary_search(int a[], int low, int high, int target) {
    int mid;
    while(low  < high) {
        mid = low + (high - low)/2;
        if(a[mid] == target) {
            return 1;
        }
        else if(a[mid] > target) {
            high = mid;
        }
        else {
            low = mid;
        }
    }
    return 0;
}

// Time Complexity = O(nlog(n)) Using Binary search
string isSubset(int a1[], int a2[], int n, int m) {
    int count = 0;
    if(m > n) {
        return "No";
    }
    sort(a1, a1+n);
    for(int i=0; i<m; i++) {
        if(binary_search(a1, 0, n-1, a2[i]) == 1) {
            count++;
        }
    }
    if(count == m) {
        return "Yes";
    }
    return "No";
}*/

// Time Complexity = O(n) Using Hashing
string isSubset(int a1[], int a2[], int n, int m) {
    int count = 0;
    if(m > n) {
        return "No";
    }
    unordered_set<int> set;
    for(int i=0; i<n; i++) {
        set.insert(a1[i]);
    }
    for(int i=0; i<m; i++) {
        if(set.find(a2[i]) != set.end()) {
            count++;
        }
    }
    if(count == m) {
        return "Yes";
    }
    return "No";
}

int main() {
    int n, m;
    cin >> n >> m;
    int arr1[n], arr2[m];
    for(int i=0; i<n; i++) {
        cin >> arr1[i];
    }
    for(int i=0; i<m; i++) {
        cin >> arr2[i];
    }
    cout << isSubset(arr1, arr2, n, m);
    return 0;
}
