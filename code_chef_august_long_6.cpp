#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n], brr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        for(int i=0; i<n; i++) {
            cin >> brr[i];
        } 
        priority_queue<pair<int, pair<int, int> > > p;
        for(int i=0; i<n; i++) {
            p.push(make_pair(p[arr[i]], make_pair(i+1, brr[i])));
        }
        int tn = 0;
        for(int i=0; i<n-1; i++) {
            if(brr[i] == brr[i+1]) {
                tn++;
            }
        }
        unordered_map<int, pair<int, int> > mp1; 
        int sum = 0, l = 0, count = 0;
        if(tn == n-1) {
            while(p.empty() == false) {
                auto it = p.top();
                sum = sum + it.first;
                auto itr = it.second;
                if(sum <= itr.second) {
                    count++;
                    mp1[itr.first] = make_pair(l, sum);
                    l = sum;
                }
                else {
                    break;
                }
            }
            cout << count << endl;
            for(auto it = mp1.begin(); it != mp1.end(); it++) {
                cout << it -> first << " ";
                auto itr = it -> second;
                cout << itr.first << " " << itr.second << endl;
            }
        }
    }
    return 0;
}