#include<bits/stdc++.h>
using namespace std;

long long int count_subset_sum(vector<int> v1, vector<int> v2, int a, int b) {
    long long count = 0;
    for(int i=0; i<v1.size(); i++) {
        int low = lower_bound(v2.begin(), v2.end(), a - v1[i]) - v2.begin();
        int high = upper_bound(v2.begin(), v2.end(), b - v1[i]) - v2.begin();
        count += high - low;
    }
    return count;
}

void solve(vector<int> &v, int arr[], int start, int end) {
    int n = end - start + 1;
    for(int i=0; i<(1<<n); i++) {
        int x = i;
        int s = 0;
        int j = start;
        while(x) {
            int l = x&1;
            if(l) {
                s = s + arr[j];
            }
            j++;
            x = x>>1;
        }
        v.push_back(s);
    }
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    vector<int> v1, v2;
    solve(v1, arr, 0, n/2-1);
    solve(v2, arr, n/2, n-1);
    sort(v2.begin(), v2.end());
    cout << count_subset_sum(v1, v2, a, b);
    return 0;
}
