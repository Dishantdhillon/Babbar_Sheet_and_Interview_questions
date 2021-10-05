#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<int> q;
    for(int i=0; i<n+m; i++) {
        int x;
        cin >> x;
        if(x != -1) {
            q.push(x);
        }
        else {
            cout << q.top() << endl;
            q.pop();
        }
    }
    return 0;
}
