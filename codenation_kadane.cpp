#include<bits/stdc++.h>
using namespace std;

int max_size(vector<int> &arr, int l, int r) {
    int prev = arr[l-1], curr = arr[l-1];
    for(int i=l; i<r; i++) {
        if((i - l) % 2 == 0) {
            prev = max(prev - arr[i], -arr[i]);
        }
        else {
            prev = max(prev + arr[i], arr[i]);
        }
        curr = max(curr, prev);
    }
    return curr;
}

vector<int> solve(vector<int> &arr, vector<vector<int> > b) {
    vector<int> vec;
    for(i=0; i<b.size(); i++) {
        if(b[i][0] == 1) {
            arr[b[i][1]] = b[i][2];
        }
        else {
            vec.push_back(max_sum(arr, b[i][1], b[i][2]));
        }
    }
    return vec;
}

int main() {
    return 0;
}