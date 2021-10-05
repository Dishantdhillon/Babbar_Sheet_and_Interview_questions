#include<bits/stdc++.h>
using namespace std;

vector<long long int> product_puzzle(vector<long long int>& arr, int n) {
    vector<long long int> vec;
    int k = -1, count = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == 0) {
            count++;
            k = i;
        }
    }
    long long int prod = 1;
    for(int i=0; i<n; i++) {
        if(i != k) {
            prod = prod * arr[i];
        }
    }
    if(k == -1) {
        for(int i=0; i<n; i++) {
            vec.push_back(prod/arr[i]);
        }
    }
    else if(count > 1) {
        for(int i=0; i<n; i++) {
            vec.push_back(0);
        }
    }
    else {
        for(int i=0; i<n; i++) {
            if(i == k) {
                vec.push_back(prod);
            }
            else {
                vec.push_back(0);
            }
        }
    }
    return vec;
}

int main() {
    int n;
    cin >> n;
    vector<long long int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    vector<long long int> ans = product_puzzle(arr, n);
    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
