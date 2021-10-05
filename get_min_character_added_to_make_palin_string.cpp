#include<bits/stdc++.h>
#include<string.h>
using namespace std;

vector<int> compute_LPS_array(string str) {
    int n = str.length();
    vector<int> lps(n);
    int len = 0, i = 1;
    lps[0] = 0;
    while(i < n) {
        if(str[i] == str[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int get_min_character(string str) {
    string revstr = str;
	reverse(revstr.begin(), revstr.end());
    str = str + '$' + revstr;
    vector<int> lps = compute_LPS_array(str);
    return (str.length() - revstr.length() - 1 - lps.back());
}

int main() {
    string str;
    cin >> str;
    cout << get_min_character(str);
    return 0;
}
