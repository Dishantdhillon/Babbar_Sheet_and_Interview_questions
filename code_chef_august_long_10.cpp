#include<bits/stdc++.h>
using namespace std;

long long int lcm(long long int a,long long int b)
{
    long long int re = __gcd(a, b);
    return (a/re)*b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        long long int arr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        for(int i=0; i<q; i++) {
            int x, l, r;
            cin >> x >> l >> r;
            long long int y;
            if(x == 1) {
                if((r-l)%2 == 1) {
                    bool b = true;
                    y = arr[r-1];
                    for(int i=r-1; i>=l; i--) {
                        if(b) {
                            y = __gcd(y, arr[i-1]);
                            b = false;
                        }
                        else {
                            y = lcm(y, arr[i-1]);
                            b = true;
                        }
                    }
                    cout << y << endl;
                }
                else {
                    bool b = false;
                    y = arr[r-1];
                    for(int i=r-1; i>=l; i--) {
                        if(b) {
                            y = __gcd(y, arr[i-1]);
                            b = false;
                        }
                        else {
                            y = lcm(y, arr[i-1]);
                            b = true;
                        }
                    }
                    cout << y << endl;
                }
            }
            else {
                if((r-l)%2 == 0) {
                    y = arr[r-1];
                    bool b = true;
                    for(int i=r-1; i>=l; i--) {
                        if(b) {
                            y = __gcd(y, arr[i-1]);
                            b = false;
                        }
                        else {
                            y = lcm(y, arr[i-1]);
                            b = true;
                        }
                    }
                    cout << y << endl;
                }
                else {
                    y = arr[r-1];
                    bool b = false;
                    for(int i=r-1; i>=l; i--) {
                        if(b) {
                            y = __gcd(y, arr[i-1]);
                            b = false;
                        }
                        else {
                            y = lcm(y, arr[i-1]);
                            b = true;
                        }
                    }
                    cout << y << endl;
                }
            }
        }
    }
    return 0;
}
