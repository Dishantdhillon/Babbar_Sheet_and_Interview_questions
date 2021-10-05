#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, p, e;
        cin >> m >> p >> e;
        bool a = false, b = false, c = false;
        if(m > 40) {
            a = true;
        }
        if(p >= 35) {
            b = true;
        }
        if(e > 60) {
            c = true;
        }
        if(a && b && c) {
            cout << "A" << endl;
        }
        else if(a && c){
            cout << "B" << endl;
        }
        else if(b && c) {
            cout << "C" << endl;
        }
        else if(a && b) {
            cout << "D" << endl;
        }
        else if(!a && !b && !c) {
            cout << "F" << endl;
        }
        else {
            cout << "E" << endl;
        }
    }
    return 0;
}