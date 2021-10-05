#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
	b = a + b;
	a = b - a;
	b = b - a;
}

// Two Pointer Approach
void shift(int arr[], int left, int right) {
    while(left <= right) {
        if(arr[left] < 0 && arr[right] < 0) {
            left++;
        }
        else if(arr[left] > 0 && arr[right] < 0) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
        else if(arr[left] > 0 && arr[right] > 0) {
            right--;
        }
        else {
            left++;
            right--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n], j = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // Approach 1
    /*for(int i=0; i<n; i++) {
        if(arr[i] < 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }*/

    shift(arr, 0, n-1);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
