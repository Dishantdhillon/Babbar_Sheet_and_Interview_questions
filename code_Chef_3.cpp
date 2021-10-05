#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        long long int arr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        vector<int> vec;
        int count = 0;
        long long int max = 0;
        for(int i=1; i<n; i++) {
        	if(arr[max] < arr[i]) {
        		max = i;
			}
		}
        while(arr[max] > 0) {
        	count = 0;
        	for(int i=0; i<n; i++) {
        		count = count + (arr[i] & 1);
        		arr[i] = arr[i] >> 1;
			}
			vec.push_back(count);	
		}
        int sum = 0;
        for(int i=0; i<vec.size(); i++) {
        	if(vec[i] % k == 0) {
        		vec[i] = vec[i]/k;
			}
			else {
				vec[i] = vec[i]/k + 1;
			}
			sum = sum + vec[i];
		}
		cout << sum << endl;
    }
    return 0;
}
