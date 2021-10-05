#include<bits/stdc++.h>
using namespace std;

int solve(int num, vector<int> arr, int segment) {
    int i, k = segment, n = num;
	deque<int> Qi(k);
    int maxE = INT_MIN;
    for (i = 0; i < k; ++i)
    {
        while ((!Qi.empty()) && arr[i] <= arr[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
    for (; i < n; ++i)
    {
        maxE = max(arr[Qi.front()], maxE);
        while ((!Qi.empty()) && Qi.front() >= i - k)
            Qi.pop_front();
        while ((!Qi.empty()) && arr[i] <= arr[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
    return maxE;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << solve(n, arr, k);
}
