#include<bits/stdc++.h>
using namespace std;

bool dfs_detect_cycle(int node, vector<int> &vis, vector<int> &dfs, vector<int> adj[]) {
    vis[node] = 1;
    dfs[node] = 1;
    for(auto it:adj[node]) {
        if(vis[it] == 0) {
            if(dfs_detect_cycle(it, vis, dfs, adj)) {
                return true;
            }
        }
        else if(dfs[node]) {
            return true;
        }
    }
    return false;
}

bool detect_cycle(int n, vector<int> adj[]) {
    vector<int> vis(n, 0);
    vector<int> dfs(n, 0);
    for(int i=0; i<n; i++) {
        if(vis[i] == 0) {
            if(dfs_detect_cycle(i, vis, dfs, adj)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<int> adj[n];
    for(int i=0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    if(detect_cycle(n, adj)) {
        cout << "True";
    }
    else {
        cout << "False";
    }
    return 0;
}
