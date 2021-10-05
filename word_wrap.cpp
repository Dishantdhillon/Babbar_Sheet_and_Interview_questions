#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > wordWrap(int arr[], int n, int k) {
    vector<int> dp(n, 0);
    vector<int> ans(n, 0);
    int i, j, current_l, cost;
    dp[n-1] = 0;
    ans[n-1] = n-1;
    for(i=n-2; i>=0; i--) {
        current_l = -1;
        dp[i] = INT_MAX;
        for(j=i; j<n; j++) {
            current_l += arr[j] + 1;
            if(current_l > k) {
                break;
            }
            if(j == n-1) {
                cost = 0;
            }
            else {
                cost = (k-current_l) * (k-current_l) + dp[j+1];
            }
            if(cost < dp[i]) {
                dp[i] = cost;
                ans[i] = j;
            }
        }
    }
    vector<vector<int> > output;
    i = 0;
    while(i < n) {
        output.push_back({i+1, ans[i]+1});
        i = ans[i] + 1;
    }
    return output;
}

int main() {
    int n;
    cin >> n;
    int arr[n], k;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cin >> k;
    vector<vector<int> > ans = wordWrap(arr, n, k);
    for(int i=0; i<ans.size(); i++) {
    	cout << "\n";
        for(int j=0; j<ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
    }
    return 0;
}
