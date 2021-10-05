#include<bits/stdc++.h>
using namespace std;

int fun(int a, int b) {
    if(a-b) {
        return a+b;
    }
    else {
        return a*b;
    }
}

int main() {
    int ans = 0;
    for(int i=1; i*i <= 20; i++) {
        ans += fun(i, i);
    }
    cout << ans;
    return 0;
}