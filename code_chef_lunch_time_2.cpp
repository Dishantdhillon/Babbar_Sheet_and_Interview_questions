#include<bits/stdc++.h>
using namespace std;

void rotate_array(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        swap(arr[i], arr[i+1]);
    }
}

int compare(vector<int> vec1, vector<int> vec2) {
    for(int i=0; i<vec1.size(); i++) {
        if(vec1[i] > vec2[i]) {
            return vec1;
        }
        else {
            return vec2;
        }
    }
} 

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n], brr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        for(int i=0; i<n; i++) {
            cin >> brr[i];
        }
        vector<int> vec1;
        vector<int> vec2 = {0};
        long long int ans = 0;
        while(j < n-1) {
            for(int i=0; i<n; i++) {
                vec1.push_back((arr[i] + brr[i])%n);
            }
            vec2 = compare(vec1, vec2);
            rotate_array(brr, n);
        }
        for(int i=0; i<vec2.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}