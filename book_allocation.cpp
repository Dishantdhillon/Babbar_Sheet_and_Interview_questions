#include<bits/stdc++.H>
using namespace std;

bool is_possible(int arr[], int n, int m, int mid) {
    int student_required = 1, curr_sum = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] > mid) {
            return false;
        }
        if(curr_sum + arr[i] > mid) {
            curr_sum = arr[i];
            student_required++;
            if(student_required > m) {
                return false;
            }
        }
        else {
            curr_sum = curr_sum + arr[i];
        }
    }
    return true;
}

int book_allocation(int arr[], int n, int m) {
    long long int sum = 0;
    for(int i=0; i<n; i++) {
        sum = sum + arr[i];
    }
    if(n < m) {
        return -1;
    }
    int start = 0, end = sum, mid, ans = INT_MAX;
    while(start <= end) {
        mid = (start + end)/2;
        if(is_possible(arr, n, m, mid)) {
            ans = mid;
            end = end - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int arr[n], m;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cin >> m;
    cout << book_allocation(arr, n, m);
}