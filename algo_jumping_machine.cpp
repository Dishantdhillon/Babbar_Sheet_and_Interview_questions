#include<bits/stdc++.h>
using namespace std;

int total_jumps(long long int x) {
	int count = 0; 
	long long int num = 0;
	while(num < x || (num - x)%2 != 0) {
		count++;
		num = num + count;
	}
	return count;
}

int main() {
    long long int x;
    cin >> x;
    cout << total_jumps(abs(x));
    return 0;
}
