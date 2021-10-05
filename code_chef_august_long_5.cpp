#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        priority_queue<pair<int, int> > p;
        for(int i=0; i<m; i++) {
            int x, y;
            cin >> x >> y;
            p.push(make_pair(x, y));
        }
        auto it = p.top();
        int x = it.first;
        int y = it.second;
        long long int sum = 0;
        if(y > n) {
            sum = n;
            sum = sum * x;
            cout << sum << endl;
        }
        else {
            sum = (n-(n/y));
            sum = sum * x;
            p.pop();
            while(p.empty() == false) {
                auto itr = p.top();
                int x1 = itr.first;
                int y1 = itr.second;
                for(int i=y; i<=n; i+=y) {
                    if(i%y1 != 0) {
                        sum += x1;
                    }
                }
                y = y1*y;
                p.pop();
            }
            cout << sum << endl;
        }
    }
    return 0;
}
