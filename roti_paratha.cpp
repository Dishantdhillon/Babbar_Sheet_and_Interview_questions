#include<bits/stdc++.h>
using namespace std;

bool is_possible(int arr[], int c, int p, int mid) {
    int time = 0;
    int paratha = 0;
    for(int i=0; i<c; i++) {
        time = arr[i];
        int j = 2;
        while(time <= mid) {
            paratha++;
            time = time + arr[i]*j;
            j++;
        }
        if(paratha >= p) {
            return true;
        }
    }
    return false;
}

int min_time(int arr[], int c, int p) {
    int ans = 0;
    int start = 0;
    int end = 1e8, mid;
    while(start <= end) {
        mid = (start + end)/2;
        if(is_possible(arr, c, p, mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int p, c;
        cin >> p;
        cin >> c;
        int arr[c];
        for(int i=0; i<c; i++) {
            cin >> arr[i];
        }
        cout << min_time(arr, c, p) << endl;
    }
    return 0;
}
