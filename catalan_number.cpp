#include<bits/stdc++.h>
using namespace std;


// catalan no. = SUMi=0,i<=n(Ci*Cn-i)
int catalan_no_recursive(int n) {
    if(n <= 1) {
        return 1;
    }
    int out = 0;
    for(int i=0; i<n; i++) {
        out = out + catalan_no_recursive(i) * catalan_no_recursive(n-i-1);
    }
    return out;
}

// catalan no. = (2*n)!/((n+1)!*n!) = MULTIPLYk=2,k<=n((n+k)/k);

int catalan_no(int n) {
	int out = 1;
	for(int i=1; i<n; i++) {
		out = out * (4*i - 2);
		out = out/(i+1);
	}
	return out;
}

int main() {
    int n;
    cin >> n;
    cout << catalan_no_recursive(n-1) << " ";
    cout << catalan_no(n);
    return 0;
}
