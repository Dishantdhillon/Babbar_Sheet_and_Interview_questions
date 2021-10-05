#include<bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    int a,b;
    for(int b=0; b<201; b++) {
        if(typeid(pow(pow(b, 5) + x, 0.2)).name() == typeid(a).name()) {
            a = pow(pow(b, 5) + x, 0.2);
            break;
        }
    }
    cout << a << " " << b;
    return 0;
}
