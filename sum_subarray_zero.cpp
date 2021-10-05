#include<bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n) {
    unordered_set<int> sumSet;
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum = sum + arr[i];
        if(sum == 0 || sumSet.find(sum) != sumSet.end()) {
            return 1;
        }
        sumSet.insert(sum);
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    if(subArrayExists) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}