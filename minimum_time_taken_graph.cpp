#include<bits/stdc++.h>
using namespace std;

void toposort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
    vis[i] = 1;
    for(auto it:adj[node]) {
        if(!vis[it]) {
            toposort(it, vis, st, adj);
        }
    }
    st.push(node);
}

void minimum_time(int n, vector<int> adj[]) {
    vector<int> vis(n+1, 0);
    stack<int> st;
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            toposort(i, vis, st, adj);
        }
    }
    int distance[n+1] = {INT_MAX};
    distance[1] = 1;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(distance[node] != INT_MAX) {
            for(auto it:adj[node]) {
                if(distance[node] + 1 < distance[it]) {
                    distance[it] = distance[node] + 1;
                }
            }
        }
    }
    for(int i=1; i<=n; i++) {
        cout << distance[i] << " ";
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<int> adj[n+1];
    for(int i=0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    minimum_time(n, adj);
    return 0;
}