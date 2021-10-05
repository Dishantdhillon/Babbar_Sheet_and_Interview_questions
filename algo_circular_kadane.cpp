#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int ans_max = arr[0], prevBest_max = arr[0], ans_min = arr[0], prevBest_min = arr[0];
    int total = arr[0];
    for(int i=1; i<n; i++) {
        prevBest_max = max(prevBest_max + arr[i], arr[i]);
        ans_max = max(ans_max, prevBest_max);
        prevBest_min = min(prevBest_min + arr[i], arr[i]);
        ans_min = min(ans_min, prevBest_min);
        total += arr[i];
    }
    if(total == ans_min) {
        cout << ans_max;
    }
    else {
        cout << max(ans_max, total-ans_min);
    }
    return 0;
}
