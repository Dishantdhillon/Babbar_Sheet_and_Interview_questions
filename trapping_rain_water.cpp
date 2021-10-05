#include<bits/stdc++.h>
using namespace  std;

int trappingWater(int arr[], int n){
    int left =0, right = n-1, left_max = 0, right_max = 0, result = 0;
    while(left <= right) {
        if(right_max <= left_max) {
            result = result + max(0, right_max - arr[right]);
            right_max = max(right_max, arr[right]);
            right--;
        }
        else {
            result = result + max(0, left_max - arr[left]);
            left_max = max(left_max, arr[left]);
            left++;
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << trappingWater(arr, n);
    return 0;
} 
