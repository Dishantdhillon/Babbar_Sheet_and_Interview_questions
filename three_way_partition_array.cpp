#include<bits/stdc++.h>
using namespace std;

void threeWayPartition(vector<int>& arr,int a, int b)
{
    int n = arr.size();
    int start = 0, end = n - 1, i = 0;
    while(i <= end) {
        if(arr[i] < a) {
            swap(arr[i++], arr[start++]);
        }
        else if(arr[i] > b) {
            swap(arr[i], arr[end--]);
        }
        else {
            i++;
        }
    }
}

int main() {
    vector<int> arr;
    int a, b, n, x;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        arr.push_back(x);
    }
    cin >> a >> b;
    threeWayPartition(arr, a, b);
    return 0;
}
