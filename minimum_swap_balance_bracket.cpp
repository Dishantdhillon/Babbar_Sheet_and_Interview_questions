#include<bits/stdc++.h>
using namespace std;

int minimumNumberOfSwaps(string S){
    int count_l = 0, count_r = 0;
    int swap = 0, imbalance = 0;
    for(int i=0; i<S.length(); i++) {
        if(S[i] == '[') {
            count_l++;
            if(imbalance > 0) {
                swap = swap + imbalance;
                imbalance--;
            }
        }
        else if(S[i] == ']') {
            count_r++;
            imbalance = count_r - count_l;
        }
    }
    return swap;
}

int main() {
    string s;
    cin >> s;
    cout << minimumNumberOfSwaps(s);
}