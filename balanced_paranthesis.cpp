#include<bits/stdc++.h>
using namespace std;

bool ispar(string x) {
    int n = x.length();
    stack<char> exp;
    for(int i=0; i<n; i++) {
        if(x[i] == '{' || x[i] == '[' || x[i] == '(') {
            exp.push(x[i]);
        }
        else if(!exp.empty()){
            if(x[i] == ')' && exp.top() == '(') {
                exp.pop();
            }
            else if(x[i] == '}' && exp.top() == '{') {
                exp.pop();
            }
            else if(x[i] == ']' && exp.top() == '[') {
                exp.pop();
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    if(exp.empty()) {
        return true;
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    if(ispar(s)) {
    	cout << "Balanced";
	}
	else {
		cout << "Not Balanced";
	}
    return 0;
}
