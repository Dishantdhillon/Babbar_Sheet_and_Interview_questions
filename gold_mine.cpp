#include<bits/stdc++.h>
using namespace std;

int max_gold(vector<vector<int> > arr, int n, int m) {
    int ans = INT_MIN, sum = 0;
    for(int i=0; i<n; i++) {
    	sum = 0;
        for(int j=0; j<m; j++) {
            if(j == 0) {
                sum = sum + arr[i][j];
            }
            else {
            	int up = i > 0 ? i-1 : i;
            	int down = i < n-1 ? i+1 : i;
                sum = sum + max(arr[i][j], max(arr[up][j], arr[down][j]));
            }
        }
        cout << sum << " ";      
        ans = max(ans, sum);
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > arr(n, vector<int> (m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << max_gold(arr, n, m);
    return 0;
}
