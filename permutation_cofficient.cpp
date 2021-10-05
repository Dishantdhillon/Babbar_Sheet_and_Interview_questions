#include<bits/stdc++.h>
using namespace std;

int permutation(int n, int k) {
    if(n < k) {
        return 0;
    }
    if(k == 1) {
        return n;
    }
    int p = 1;
    for(int i=0; i<k; i++) {
    	p = p * (n - i);
	}
	return p;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << permutation(n, k);
    return 0;
}
