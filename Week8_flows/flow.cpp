
// #include <bits/stdc++.h> // includes all; gcc only
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      begin(a),end(a)

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n,m; cin>>n>>m;
    struct Edge { int from, to; ll cap; };
    vector<Edge> edges;
    vector<vector<int>> adj(n); // indices into edges
    rep(i,m) {
        int a,b,c; cin>>a>>b>>c;
        --a,--b;
        edges.emplace_back(a,b,c);
        edges.emplace_back(b,a,c);
        adj[a].push_back(2*i);
        adj[b].push_back(2*i+1);
    }

    ll flow = 0;
    int s = 0, t = 1;
    while(true) {
        queue<int> q{{s}};
        vector inc(n,-1); // indices into edges
        while(!empty(q)) {
            auto v = q.front(); q.pop();
            for(auto idx : adj[v]) {
                auto [_,u,c] = edges[idx];
                if(inc[u]!=-1 || !c) continue;
                q.push(u);
                inc[u] = idx;
            }
        }

        if(inc[t]==-1) break;

        ll aug = numeric_limits<ll>::max();
        for(int v=t; v!=s; v=edges[inc[v]].from)
            aug = min(aug,edges[inc[v]].cap);

        flow += aug;
        for(int v=t; v!=s; v=edges[inc[v]].from) {
            edges[inc[v]].cap -= aug;
            edges[inc[v]^1].cap += aug;
        }
    }

    cout << flow << '\n';

    return 0;
}
