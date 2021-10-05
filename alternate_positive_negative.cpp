#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    b = a + b;
    a = b - a;
    b = b - a;
}

void rightRotate(int arr[], int n, int outofplace, int index) {
    int temp = arr[index];
    for(int i=index; i>outofplace; i--) {
        arr[i] = arr[i-1];
    }
    arr[outofplace] = temp;
}

void alternate_positive_negative(int arr[], int n) {
    int outofplace = -1;
    for(int i=0; i<n; i++) {
        if(outofplace >= 0) {
            if((arr[i] >=0 && arr[outofplace] < 0) || (arr[i] <0 && arr[outofplace] >=0)) {
                rightRotate(arr, n, outofplace, i);

	            if(i - outofplace >= 2) {
	                outofplace = outofplace + 2;
	            }
	            else {
	                outofplace = -1;
	            }
        	}
        }
        if(outofplace == -1) {
            if((arr[i] >=0 && i%2 == 0) || (arr[i] <0 && i%2 == 1)) {
                outofplace = i;
            }
        }
    }
}

/*void alternate_positive_negative(int arr[], int n) {
    int neg = 0, pos = 0;
    sort(arr, arr+n);
    if(arr[0] >= 0) {
        return;
    }
    for(int i=0; i<n; i++) {
        if(arr[i] < 0) {
            neg++;
        }
        else {
            pos++;
        }
    }
    int j = neg;
    for(int i=1; i<neg && j<n; i+2) {
        if(neg % 2 == 0) {
            swap(a[i], a[j+1])
            j = j + 2;
        }

    }
}*/

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[n];
    }
    alternate_positive_negative(arr, n);
    for(int i=0; i<n; i++) {
    	cout << arr[i] << " ";
	}
    return 0;
}

