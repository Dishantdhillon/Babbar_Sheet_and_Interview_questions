#include<bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(), a.end());
    long long min = a[m-1] - a[0];
    for(long long i=1; i<n-m+1; i++) {
        if(min > (a[m+i-1] - a[i])) {
            min = a[m+i-1] - a[i];
        }
    }
    return min;
}

int main() {
    long long int n, m;
    cin >> n;
    vector<long long> v;
    for(long long int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
    }
    cin >> m;
    cout << findMinDiff(v, n, m);
    return 0;
}