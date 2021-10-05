#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long int solve(string str) {
	long long int n = str.length();
    long long int ans = 0;
    long long int flag = 0, i;
    for(i=0; i<n; i++) {
        if(str[i] == 'X') {
            flag = 1;
            break;
        }
        else if(str[i] == 'O') {
            flag = 2;
            break;
        }
    }
    if(flag == 0) {
        return 0;
    }
    for(long long int j=i+1; j<n; j++) {
        if(str[j] == 'X' && flag == 2) {
            ans++;
            flag = 1;
        }
        else if(str[j] == 'O' && flag == 1) {
            ans++;
            flag = 2;
        }
    }
    return ans;
}

string appended(string u, int k) {
    string str = "";
    for(int i=0; i<k; i++) {
        if(u[i] == '.') {
            str = str + str;
        }
        else {
            str = str + u[i];
        }
    }
    return str;
}

int main() {
    int t, l = 1;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        string u, str;
        cin >> u;
        str = appended(u, k);
        long long int n = str.length();
        long long int sum = 0;
        for(long long int i=0; i<n; i++) {
            for(long long int j=2; j<=n-i; j++) {
                sum = (sum % mod + solve(str.substr(i, j)) % mod) % mod;
            }
        }
        cout << "Case #" << l << ": " << sum % mod << endl;
        l++;
    }
    return 0;
}
