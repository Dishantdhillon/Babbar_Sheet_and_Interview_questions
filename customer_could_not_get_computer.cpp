#include<bits/stdc++.h>
using namespace std;

int not_get_computer(int n, string str) {
    int len = str.length(), count = 0;
    unordered_set<char> set;
    set.insert(str[0]);
    n--;
    for(int i=1; i<len; i++) {
        if(set.find(str[i]) != set.end()) {
            if(n < 0) {
                count++;
            }
            n++;
        }
        else {
            set.insert(str[i]);
            n--;
        }
    }
    return count;    
}

int main() {
    int n;
    string str;
    cin >> n;
    cin >> str;
    cout << not_get_computer(n, str);
}