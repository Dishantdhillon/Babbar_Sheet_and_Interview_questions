#include<bits/stdc++.h>
using namespace std;

string mobile_number_keypad(string input) {
    int n = input.length();
    string output = "";
    string str[] = {"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666","7","77","777","7777","8","88","888","9","99","999","9999"};
    for(int i=0; i<n; i++) {
        if(input[i] == ' ') {
            output = output + "0"; 
        }
        else {
            int position = input[i] - 'A';
            output = output + str[position];
        }
    }
    return output;
}

int main() {
    string input;
    cin >> input;
    cout << mobile_number_keypad(input);
    return 0;
}