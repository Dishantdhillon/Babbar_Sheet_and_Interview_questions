#include<bits/stdc++.h>
using namespace std;

void rotate_90(int **mat, int n) {
    for(int i=0; i<n/2; i++) {
        for(int j=i; j<n-1-i; j++) {
        	int temp = mat[i][j];
        	mat[i][j] = mat[n-1-j][i];
        	mat[n-1-j][i] = mat[n-1-i][n-1-j];
        	mat[n-1-i][n-1-j] = mat[j][n-1-i];
        	mat[j][n-1-i] = temp;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int** arr = new int*[n];                
    for(int i=0; i<n; i++)
        arr[i] = new int[n];
        
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    rotate_90(arr, n);
    for(int i=0; i<n; i++) {
    	cout << "\n";
        for(int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
    }
}
