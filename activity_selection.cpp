#include<bits/stdc++.h>
using namespace std;

int count_max_meetings(int start[], int end[], int n) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > p;
    for(int i=0; i<n; i++) {
        p.push(make_pair(end[i], start[i]));
    }
    int count = 0;
    auto it = p.top();
    int s = it.second;
    int e = it.first;
    p.pop();
    while(!p.top()) {
        auto itr = p.top();
        p.pop();
        if(itr.second >= e) {
            s = itr.second;
            e = itr.first;
            count++;
        }
    }
    return count+1;
}

int main() {
    int n;
    cin >> n;
    int start[n], end[n];
    for(int i=0; i<n; i++) {
        cin >> start[i];
    }
    for(int i=0; i<n; i++) {
        cin >> end[i];
    }
    cout << count_max_meetings(start, end, n);
    return 0;
}
