#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(nlog(n)
void more_than_ndk(int arr[], int n, int k) {
    int count = 1;
    sort(arr, arr+n);
    for(int i=1; i<n; i++) {
        if(arr[i] == arr[i-1]) {
            count++;
        }
        else {
            if(count > n/k) {
                cout << arr[i-1] << " ";
            }
            count = 1;
        }
        if(i == n-1 && count>n/k) {
        	cout << arr[i];
		}
    }
}


/*// Time Complexity = O(n)
void more_than_ndk(int arr[], int n, int k) {
    unordered_set<int> set;
    for(int i=0; i<n; i++) {
        set.insert(arr[i]);
    }
    for(int i=0; i<n; i++) {
        if(set.find(arr[i]) == set.end()) {
            int j = arr[i];
            while(set.find(j) != set.end()) {
                j++;
            }
            if((j - arr[i]) > n/k) {
                cout << arr[i] << " ";
            }
        }
    }
}*/

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    more_than_ndk(arr, n, k);
}
