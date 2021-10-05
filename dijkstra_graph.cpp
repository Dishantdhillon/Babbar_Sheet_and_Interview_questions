#include<bits/stdc++.h>
using namespace std;

void shortest_distance_dijkstra(int src, int n, vector<pair<int, int> > adj[]) {
    int distance[n];
    for(int i=0; i<n; i++) {
        distance[i] = INT_MAX;
    }
    distance[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, src));
    while(!pq.empty()) {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        for(auto it:adj[node]) {
            if(distance[it.first] > it.second + dis) {
                distance[it.first] = it.second + distance[node];
                pq.push(make_pair(distance[it.first], it.first));
            }
        }
    }
    for(int i=0; i<n; i++) {
        cout << distance[i] << " ";
    }
}


int main() {
    int n, e;
    cin >> n >> e;
    vector<pair<int, int> > adj[];
    for(int i=0; i<e; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }
    int src;
    cin >> src;
    shortest_distance_dijkstra(src, n, adj);
    return 0;
}
