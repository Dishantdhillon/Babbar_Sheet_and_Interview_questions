#include<bits/stdc++.h>
using namespace std;

void subsequenceRec(string str, int n, int index, string result) {
    if(index == n) {
    	return;
	}
	
	if(!result.empty()) {
		cout << result << " ";
	}
	
	for(int i=index+1; i<n; i++) {
        result = result + str[i];
        subsequenceRec(str, n, i, result);
        result = result.erase(result.length()-1);
    }
    return;
}

void subsequence(string str) {
	subsequenceRec(str, str.length(), -1, "");
}

int main() {
    string s;
    cin >> s;
    subsequence(s);
    return 0;
}
