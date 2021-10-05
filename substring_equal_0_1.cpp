#include<bits/stdc++.h>
using namespace std;

int substring_equal_0_1(string s) {
    int n = s.length();
    int count = 0, zero = 0, one = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == '0') {
            zero++;
        }
        else {
            one++;
        }
        if(zero == one) {
            count++;
        }
    }
    if(zero != one) {
    	return -1;
	}
    return count;
}

int main() {
    string s;
    cin >> s;
    cout << substring_equal_0_1(s);
    return 0;
}
