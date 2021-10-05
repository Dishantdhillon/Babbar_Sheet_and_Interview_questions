#include<bits/stdc++.h>
using namespace std;

int pivot_index(int arr[], int n) {
    int left = 0, right = n-1, ans = 0;
    int suml = arr[left], sumr = arr[right];
    while(left < right) {
        if(suml > sumr) {
            right--;
            sumr = sumr + arr[right];
        }
        else if(suml < sumr) { 
        	left++;
        	suml =  suml + arr[left];
        }
        else {
            left++;
            suml = suml + arr[left];
            right--;
            sumr = sumr + arr[right];
        }
    }
    if(suml == sumr) {
    	return left;	
	}
	return -1;
}

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
    	cout << pivot_index(arr, n) << "\n";
	}
    return 0;
}
