#include<bits/stdc++.h>
using namespace std;

int buy_sell_stock(int arr[], int n) {
    int minprice = INT_MAX;
    int maxprofit = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < minprice)
            minprice = arr[i];
        else if (arr[i] - minprice > maxprofit)
            maxprofit = arr[i] - minprice;
    }
    return maxprofit;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n ; i++) {
        cin >> arr[i];
    }
    int profit = buy_sell_stock(arr, n);
    cout << profit;
    return 0;
}
