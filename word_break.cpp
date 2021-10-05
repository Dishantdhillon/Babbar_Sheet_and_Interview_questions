#include<bits/stdc++.h>
using namespace std;

int compare_string(string s, vector<string> &B) {
    int n = B.size();
    for(int i=0; i<n; i++) {
        if(B[i].compare(s) == 0) {
            return 1;
        }
    }
    return 0;
}

int word_break(string s, vector<string> &B) {
    int n = s.length();
    if(n == 0) {
    	return 1;
	}
    for(int i=1; i<=n; i++) {
        if(compare_string(s.substr(0,i), B) && word_break(s.substr(i, n-i), B)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    string s;
    vector<string> B;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string x;
        cin >> x;
        B.push_back(x);
    }
    cin >> s;
    cout << word_break(s, B);
    return 0;
}
