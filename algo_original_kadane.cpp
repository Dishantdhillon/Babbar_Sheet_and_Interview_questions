#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int ans = arr[0], prevBest = arr[0];
    for(int i=1; i<n; i++) {
        prevBest = max(prevBest+arr[i], arr[i]);
        ans = max(ans, prevBest);
    }
    cout << ans;
    return 0;
}
