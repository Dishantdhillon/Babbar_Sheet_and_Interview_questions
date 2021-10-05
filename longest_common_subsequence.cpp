#include<bits/stdc++.h>
using namespace std;

int lcs(int x, int y, string s1, string s2) {

    // Recursive
    /*if(x == 0 || y == 0) {
        return 0;
    }
    else if(s1[x-1] == s2[y-1]) {
        return 1 + lcs(x-1, y-1, s1, s2);
    }
    else {
        return max(lcs(x-1, y, s1, s2), lcs(x, y-1, s1, s2));
    }*/
        
    // Dynamic Programming    
    int l[x+1][y+1];
    for(int i=0; i<=x; i++) {
        for(int j=0; j<=y; j++) {
            if(i == 0 || j == 0) {
                l[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]) {
                l[i][j] = l[i-1][j-1] + 1;
            }
            else {
                l[i][j] = max(l[i-1][j], l[i][j-1]);
            }
        }
    }
    return l[x][y];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1.length(), s2.length(), s1, s2);
    return 0;
}