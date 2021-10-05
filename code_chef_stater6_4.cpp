#include<bits/stdc++.h>
using namespace std;

long long int cal_even_pair(int arr[], int n, int left, int right) {
	
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        int arr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr+n);
        while(q--) {
            int l, r;
            cin >> l >> r;
            int left = -1, right = -1;
            for(int i=0; i<n; i++) {
                if(arr[i] > l) {
                    if(i == 0) {
                        left = 0;
                        break;
                    }
                    else {
                        left = i-1;
                        break;
                    }
                }
                else {
                	if(arr[i] == l && i == n-1) {
                		left = n-1;
                		break;
					}
				}
            }
            for(int i=0; i<n; i++) {
            	if(arr[i] > r) {
                    right = i-1;
                    break;
                }
                else {
                    if(i == n-1) {
                        right = i;
                        break;
                    }
                }
			}
            cal_even_pair(arr, n, left, right);
        }
    }
    return 0;
}
