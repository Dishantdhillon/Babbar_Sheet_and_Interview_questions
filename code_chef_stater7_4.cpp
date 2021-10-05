#include<bits/stdc++.h>
using namespace std;

long long int ceil(long long int a) {
	if(a < 0) {
		return a/2;
	}
	long long int b = a/2;
	b = b * 2 - 1;
	if(b == 0) {
		return a/2;
	}
	else {
		return a/2 + 1;
	}
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        long int a, b;
        cin >> a >> b;
        if(a == b) {
            cout << 0 << endl;
        }
        else {
            long long int x = b - (b - a)/2;
            //cout << x << endl;
            long long int a1 = (x - a)/2;
            long long int b1 = (b - x)/2;
            a1 = ceil(a1);
            b1 = ceil(b1);
            cout << a1 + b1;
        }
    }
    return 0;
}
