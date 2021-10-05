#include<bits/stdc++.h>
using namespace std;

void inorder(int arr[], int n, vector<int> &v, int index) {
    if(index >= n) {
        return;
    }
    inorder(arr, n, v, 2*index + 1);
    v.push_back(arr[index]);
    inorder(arr, n, v, 2*index + 2);
}

int min_swaps(vector<int> arr) {
    int n = arr.size();
    int ans = 0;
    vector<int> temp = arr;
    map<int, int> m;
    sort(temp.begin(), temp.end());
    for(int i=0; i<n; i++) {
        m[arr[i]] = i;
    }
    for(int i=0; i<n; i++) {
        if(arr[i] != temp[i]) {
            ans++;
            int k = arr[i];
            swap(arr[i], arr[m[temp[i]]]);
            m[k] = m[temp[i]];
            m[temp[i]] = i;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    vector<int> v;
    inorder(arr, n, v, 0);
    for(int i=0; v.size(); i++) {
    	cout << v[i] << " ";
	}
    cout << min_swaps(v);
}
