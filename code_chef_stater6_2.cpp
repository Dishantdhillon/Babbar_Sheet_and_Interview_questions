#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        if(6 > x+y) {
        	cout << float((6-(x+y)))/6 << endl;
		}
		else {
			cout << 0 << endl;
		}
    }
    return 0;
}
