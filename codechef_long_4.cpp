#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, x;
	    cin >> n >> x;
	    int arr[n];
	    for(int i=0; i<n; i++) {
	        cin >> arr[i];
	    }
	    map<int, int> mp;
	    for(int i=0; i<n; i++) {
	        mp[arr[i]]++;
	    }
	    int maxf = 0, maxE;
	    for(auto it = mp.begin(); it != mp.end(); it++) {
	        if(maxf < it -> second) {
	            maxE = it -> first;
	        }
	    }
	    for(int i=0; i<n; i++) {
	        mp[arr[i]^x]++;
	    }
	    int maxf2 = 0, maxE2;
	    for(auto it = mp.begin(); it != mp.end(); it++) {
	        if(maxf2 < it -> second) {
	            maxE2 = it -> first;
	        }
	    }
	    if(maxf >= maxf2) {
	        cout << maxf << " " << 0 << endl;
	    }
	    else if(maxE == maxE2) {
	        cout << maxf2 << " " << maxf2 - maxf << endl;
	    }
	    else {
	        map<int, int> mp2;
	        for(int i=0; i<n; i++) {
	            mp2[arr[i]]++;
	        }
	        if(mp2.find(maxE2) != mp.end()) {
	            auto it = mp2.find(maxE2);
	            cout << maxf2 << " " << maxf2 - it -> first << endl;
	        }
	        else {
	            cout << maxf2 << " " << maxf2 << endl;
	        }
	    }
	}
	return 0;
}
