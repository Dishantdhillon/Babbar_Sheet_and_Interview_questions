#include<bits/stdc++.h>
using namespace std;

int count_pairs(int arr[], int n) {
	int count = 0;
	map<int, int> mp;
	for(int i=0; i<n; i++) {
		mp[arr[i]%60]++;
	}
	for(int i=1; i<59; i++) {
		if(i != 30)
			count += (mp[i] * mp[59-i+1])/2;
		else {
			if(mp[i] >= 2) {
				count += 1;
			}
		}	
	}
	if(mp[0] >= 2) {
		count += 1;
	}
	return count;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << count_pairs(arr, n);
    return 0;
}
