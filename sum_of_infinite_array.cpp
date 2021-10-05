#define mod 1000000007
#include<bits/stdc++.h>

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    vector<int> v;
    vector<long long> preSum(n+1);
    preSum[0] = 0;
    for(int i=0; i<n; i++) {
        preSum[i+1] = (preSum[i] % mod + arr[i] % mod) % mod;
    }
    for(int i=0; i<q; i++) {
        long long int l = queries[i][0];
        long long int r = queries[i][1];
        l--;
        long long int ans = (preSum[r%n] - preSum[l%n] + ((preSum[n] * ((r/n - l/n) % mod)))) % mod;
        v.push_back(ans % mod);
    }
    return v;
}