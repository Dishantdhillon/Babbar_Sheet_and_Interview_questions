#include<bits/stdc++.h>
using namespace std;

PairInt solve(int numPackages, int truckSpace, ArrayList<Integer> Space) {
    sort(Space, Space + numPackages);
    truckSpace -= truckSpace % 60;
    int a = 0, b = numPackages-1;
    int c = - 1, d = -1;
    while(a < b) {
        if(Space[a] + Space[b] == truckSpace) {
            c = Space[a];
            d = Space[b];
            break;
        }
        else if(Space[a] + Space[b] > truckSpace) {
            b--;
        }
        else if(Space[a] + Space[b] < truckSpace && ((Space[a] + Space[b])%60 == 0)) {
            c = max(c, Space[a]);
            d = max(d, Space[b]);
            a++;
        }
        else {
            a++;
        }
    }
    PairInt* p = PairInt(c, d);
    return p;
}