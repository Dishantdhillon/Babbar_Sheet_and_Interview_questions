#include<bits/stdc++.h>
using namespace std;

long int solve(vector<int> batch, vector<int> time, vector<int> num, int n) {
    long int minT = INT_MIN, t;
    for(int i=0; i<n; i++) {
        t = ceil(double(num[i])/double(batch[i]));
        t = t * time[i];
        minT = max(minT, t);
    }
    return minT;
}

int main() {
    int n;
    cin >> n;
    vector<int> batch(n), time(n), num(n);
    for(int i=0; i<n; i++) {
        cin >> batch[i];
    }
    for(int i=0; i<n; i++) {
        cin >> time[i];
    }
    for(int i=0; i<n; i++) {
        cin >> num[i];
    }
    cout << solve(batch, time, num, n);
    return 0;
}
