#include<bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	int i = 0, j = 0, ans = 0, k;
	while(i<n && j<m) {
	    int count = 0;
	    if(arr[i][j] == 1) {
	        count = count + m - j;
	        i++;
	        j = 0;
	        if(count > ans) {
	            k = i-1;
	        }
	        ans = max(ans, count);
	    }
	    else if(j == m-1) {
	        i++;
	        j = 0;
	    }
	    else {
	        j++;
	    }
	}
	if(ans == 0) {
	    return -1;
	}
	return k;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > arr(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << rowWithMax1s(arr, n, m);
    return 0;
}