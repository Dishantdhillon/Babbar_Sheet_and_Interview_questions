#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, l;
        cin >> n >> m >> l;
        vector<int> vec;
        vector<vector<int> > arr(m, vec);
        for(int i=0; i<m; i++) {
        	int k;
        	cin >> k;
        	vec.push_back(k);
        	for(int j=0; j<k; j++) {
        		int x;
        		cin >> x;
        		vec.push_back(x);
			}
			arr.push_back(vec);
		}
		int f_arr[l];
		for(int i=0; i<l; i++) {
			cin >> f_arr[i];
		}
		std::vector<std::vector<int>>::iterator itCol;
		std::vector<int>::iterator itRow;
		for (itRow = t.begin(); itRow != t.end(); itRow++){
			for(itCol = itRow->begin(); itCol != itRow->end(); itCol++) {
				if(arr[k] == itCol) {
					int x = itRow;
				}
			}
		}
    }
    return 0;
}
