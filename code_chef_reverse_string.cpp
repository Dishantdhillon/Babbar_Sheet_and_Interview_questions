#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int t;
	cin >> t;
    std::vector<std::string> v;
    for(int i=0; i<t; i++) {
        getchar();
	    getline(cin, s);
	    cout << s << endl;
        for(int i=0; i<s.length(); i++) {
            /*if(s[i] == '.' && i != s.length()-1) {
                s.erase(i, 2);
            }*/
	        if(s[i] == '.' || s[i] == ':' || s[i] == ';' || s[i] == '`' || s[i] == '`' || s[i] == ',') {
	            s.erase(s.begin()+i);
	        }
	    }
	    string result = "";
	    for(int i=s.length()-1; i>=0; i--) {
	    	if(i == 0) {
	    		for(int j=i; j<s.length() && s[j] != ' '; j++) {
	    			result = result + s[j];
				}
				result = result + " ";
			}
			else if(s[i] == ' ') {
	    		for(int j=i+1; j<s.length() && s[j] != ' '; j++) {
	    			result = result + s[j];
				}
				result = result + " ";
			}
		}
        v.push_back(result);
    }
	for(int i=v.size()-1; i>=0; i--) {
        std::cout << v[i] << std::endl;
    }
	return 0;
}

