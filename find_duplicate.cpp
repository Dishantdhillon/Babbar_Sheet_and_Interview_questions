#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(int arr[], int n) {
        int i = 0, j = 0;
        if(n == 1) {
        	return -1;
		}
        while(j<n) {
            i = i + arr[j];
            j++;
        }
        return i - n*(n-1)/2;
    }
};

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    Solution obj;
    int output = obj.findDuplicate(arr, n);
    cout << output;
    retrun 0;
}
