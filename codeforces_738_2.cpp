#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '?' && s[i+1] == 'B') {
                s[i] = 'R';
            }
            else if(s[i] == '?' && s[i+1] == '?') {
                if(s[i-1] == 'B') {
                    s[i] = 'R';
                }
                else if(s[i-1] == 'R'){
                    s[i] = 'B';
                }
            }
            else if(s[i] == '?' && s[i+1] == 'R') {
                s[i] = 'B';
            }
            else if(s[i] == '?' && i == s.length()-1) {
            	if(s[i-1] == 'B') {
            		s[i] = 'R';
				}
				else {
					s[i] = 'B';
				}
			}
        }
        for(int i=s.length()-1; i>=0; i--) {
        	if(s[i] == '?') {
        		if(s[i+1] == 'B') {
        			s[i] = 'R';
				}
				else {
					s[i] = 'B';
				}
			}
		}
        cout << s << endl;
    }
    return 0;
}
