#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[], int low, int high, int k) {
	int num = 0, mid, point;
    while(low <= high) {
    	mid = low + (high - low)/2;
        if(a[mid] == k) {
            num++;
            if(point == 0) {
            	low = mid + 1;
			}
			else if(point == 1) {
				high = mid - 1;
			}
            else {
                for(int i=1; a[mid-i] == k; i++) {
                    num++;
                }
                for(int i=1; a[mid+i] == k; i++) {
                    num++;
                }
            }
        }
        else if(a[mid] < k) {
            low = mid + 1;
            point = 0;
        }
        else {
            high = mid-1;
            point = 1;
        }
    }
    return num;
}

int main() {
    int n, m, count = 0;
    cout << "First array\n"; 
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << "\nSeccond array\n";
    cin >> m;
    int b[m];
    for(int i=0; i<m; i++) {
        cin >> b[i];
    }
    
    // Time Complexity = O(n*m)
    /*for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(a[i] == b[j]) {
                count++;
            }
        }
    }
	cout << "Union is " << i + j- count;*/
	
	//Time Complexity = O(n+m)
    /*int i =0, j=0; 
    while(i<n && j<m) {
    	if(a[i] < b[j]) {
    		count++;
    		i++;
		}
		else if(a[i] > b[j]) {
			count++;
			j++;
		}
		else{
			count++;
			i++;
			j++;
		}
	}
	count = count + n + m - i - j;
    cout << "Union is " << count;*/

    // Time Complexity = O(min(nlogm, mlogn))
    int i = n<m?n:m;
    for(int j=0; j<i; j++) {
        if(i == n) {
            count = count + binary_search(b, 0, m-1, a[j]);
        }
        else {
            count  = count + binary_search(a, 0, n-1, b[j]);
        }
    }
    cout << "Union is " << n + m - count;
    return 0;
}
