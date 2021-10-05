int minSwap(int *arr, int n, int k) {
    int count = 0, bad = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] <= k) {
            count++;
        }
    }
    for(int i=0; i<count; i++) {
        if(arr[i] > k) {
            bad++;
        }
    }
    int ans = bad;
    for(int i = 0, j = count; j < n; j++, i++) {
        if(arr[i] > k) {
            bad--;
        }
        if(arr[j] > k) {
            bad++;
        }
        ans = min(ans, bad);
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cin >> k;
    cout << minSwap(arr, n, k);
    return 0;
}