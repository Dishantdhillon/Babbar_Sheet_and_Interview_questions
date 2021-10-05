#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n][5];
        for(int i=0; i<n; i++) {
            for(int j=0; j<5; j++) {
                cin >> arr[i][j];
            }
        }
        int r = 0;
        for(int i=0; i<n; i++) {
            r = 0;
            for(int j=0; j<n; j++) {
                if(i != j) {
                    int count = 0;
                    for(int k=0; k<5; k++) {
                        if(arr[i][k] < arr[j][k]) {
                            count++;
                        }
                    }
                    if(count < 3) {
                        break;
                    }
                    else {
                        r++;
                    }
                }
            }
            if(r == n-1) {
            	cout << i+1 << endl;
                break;
            }
            else {
                r = 0;
            }
        }
        if(r != n-1) {
        	cout << -1 << endl;
		}
    }
    return 0;
}
