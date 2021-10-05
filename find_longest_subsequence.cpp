#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(nlog(n))
int findLongestConseqSubseq(int arr[], int n) {
	sort(arr, arr+n);
    int ans = 0, count = 0;
    vector<int> vec;
    vec.push_back(arr[0]);
    for(int i=1; i<n; i++) {
        if(arr[i] != arr[i-1]) {
            vec.push_back(arr[i]);
        }
    }
    for(int i=0; i<vec.size(); i++) {
        if((i>0) && (vec[i] == vec[i-1]+1)) {
            count++;
        }
        else {
            count = 1;
        }
        ans = max(ans, count);
    }
    return ans;
}

/*// Time Complexity = O(n)
int findLongestConseqSubseq(int arr[], int n) {
	int ans = 0, count = 0;
	unordered_set<int> set;
	for(int i=0; i<n; i++) {
		set.insert(arr[i]);
	}
	for(int i=0; i<n; i++) {
		if(set.find(arr[i]-1) == set.end()) {
			int j = arr[i];
			while(set.find(j) != set.end()) {
				j++;
			}
			ans = max(ans, j - arr[i]);
		}
	}
	return ans; 
}*/

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    cout << findLongestConseqSubseq(arr, n);
    return 0;
}
