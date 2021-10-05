#include<bits/stdc++.h>
using namespace std;

bool shuffle(string s1, string s2, string result) {
    int n1 = s1.length();
    int n2 = s2.length();
    int n3 = result.length();
    if((n1 + n2) != n3) {
        return 0;
    }
    int k = 0, i = 0, j = 0;
    while(k < n3) {
        if(i < n1 && s1[i] == result[k]) {
            i++;
            k++;
        }
        else if(j < n2 && s2[j] == result[k]) {
            j++;
            k++;
        }
        else {
            return 0;
        }
    }
    if(i < n1 || j < n2) {
        return 0;
    }
    return 1;
}

int main() {
	string s1, s2, result;
	cin >> s1 >> s2 >> result;
	cout << shuffle(s1, s2, result);
	return 0;
}
