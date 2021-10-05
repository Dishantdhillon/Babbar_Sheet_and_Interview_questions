#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
	b = a + b;
	a = b - a;
	b = b - a;
}

// Two Pointer Approach
void shift(int arr[], int left, int right) {
    
}

int main() {
    int n;
    cin >> n;
    int arr[n], k = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // Insertion sort Approach 
    for(int i=0; i<n; i++) {
        int j = i;
        if(arr[i] < 0) {
            while(j > k) {
                swap(arr[j], arr[j-1]);
                j--;
            }
            k++;
        }
    }


    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}