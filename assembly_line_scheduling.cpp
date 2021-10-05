#include<bits/stdc++.h>
using namespace std;

int carAssembly(int a[][4], int t[][4], int i[], int f[]) {
    int t1[4], t2[4];
    t1[0] = i[0] + a[0][0];
    t2[0] = i[1] + a[1][0];
    for(int i=1; i<4; i++) {
        t1[i] = min(t1[i-1] + a[0][i], t2[i-1] + a[0][i] + t[1][i]);
        t2[i] = min(t2[i-1] + a[1][i], t1[i-1] + a[1][i] + t[0][i]);
    } 
    return min(t1[3] + f[0], t2[3] + f[1]);
}

int main() {
    int a[2][4] = {{4, 5, 3, 2},{2, 10, 1, 4}};
    int t[2][4] = {{0, 7, 4, 5},{0, 9, 2, 8}};
    int i[] = {10, 12};
    int f[] = {18, 7};
    cout << carAssembly(a, t, i, f);
    return 0;
}
