#include<bits/stdc++.h>
using namespace std;

string returnPalin(string S, int start, int end) {
    string result;
    for(int i=start; i<= end; i++) {
        result = result + S[i];
    }
    return result;
}

string longestPalin (string S)
{
    int n = S.length();
    int max_length = 1;
    int low, high, start = 0;
    for(int i=1; i<n; i++) {
        low = i-1;
        high = i;
        while(low >= 0 && high < n && S[low] == S[high]) {
            if(high - low + 1 > max_length) {
                start = low;
                max_length = high - low + 1;
            }
            low--;
            high++;
        }
        low = i-1;
        high = i+1;
        while(low >= 0 && high < n && S[low] == S[high]) {
            if(high - low + 1 > max_length) {
                start = low;
                max_length = high - low + 1;
            }
            low--;
            high++;
        }
    }
    return returnPalin(S, start, start + max_length-1);
}

int main() {
    string s;
    cin >> s;
    cout << longestPalin(s);
    return 0;
}