#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define all(x) (x).begin(), (x).end()

// v64 bellman_ford(vvp64& graph, v64& change, ll node) {
//   ll n = graph.size();
//   v64 dist(n, 0);  // 0 in the case where we are doing johnson
//   v64 pre(n, NULL);
//   dist[node] = 0;
//   forn(i, n - 1) {
//     forn(u, n) {
//       for (auto edge : graph[u]) {
//         if (u != n) {  // so we want to ignore the change cost the first it
//           if (dist[edge.fi] > dist[u] + change[u] + edge.se) {
//             dist[edge.fi] = dist[u] + change[u] + edge.se;
//             pre[edge.fi] = u;
//           }
//         } else {
//           if (dist[edge.fi] > dist[u] + edge.se) {
//             dist[edge.fi] = dist[u] + edge.se;
//             pre[edge.fi] = u;
//           }
//         }
//       }
//     }
//   }
//   return dist;
// }

v64 dijkstra(vvp64& graph, ll node) {
  ll n = graph.size();
  v64 dist(n, INF);
  dist[node] = 0;
  priority_queue<p64, vector<p64>, greater<p64>> pq;  // min heap
  pq.push({0, node});                                 // {distance, vertex}

  while (!pq.empty()) {
    ll d = pq.top().fi;
    ll u = pq.top().se;
    pq.pop();

    if (d > dist[u]) continue;

    for (auto& edge : graph[u]) {
      ll v = edge.fi;
      ll w = edge.se;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }

  return dist;
}
vv64 floydwarshall(vvp64& graph, v64& change) {
  ll n = graph.size();
  vv64 dist(n, v64(n, INF));
  forn(i, n) {
    dist[i][i] = 0;
    for (auto u : graph[i]) {
      dist[i][u.fi] = u.se - change[i];  // initially we dont have any change times
    }
  }
  forn(k, n) {
    forn(i, n) {
      forn(j, n) { dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j] + change[k]); }
    }
  }
  return dist;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  ll t, u, v, n, m, k, w;
  string s;
  char c;
  cin >> n;
  vp64 prof(n + 1);
  forn(i, n) { cin >> prof[i + 1].fi >> prof[i + 1].se; }
  cin >> m;
  vvp64 graph(n + 1);
  forn(i, m) {
    cin >> u >> v;
    graph[u].emplace_back(v, ((prof[u].fi - prof[v].fi) * (prof[u].fi - prof[v].fi)) + ((prof[u].se - prof[v].se) * (prof[u].se - prof[v].se)));
    graph[v].emplace_back(u, ((prof[u].fi - prof[v].fi) * (prof[u].fi - prof[v].fi)) + ((prof[u].se - prof[v].se) * (prof[u].se - prof[v].se)));
  }
  vv64 apsp(n + 1);
  forn(i, n) { apsp[i + 1] = dijkstra(graph, i + 1); }
  ll q;
  cin >> q;
  forn(i, q) {
    cin >> u >> v;
    if (apsp[u][v] != INF) {
      cout << apsp[u][v] << ln;
    } else {
      cout << "BRIBE DM WITH FOOD" << ln;
    }
  }
  return 0;
}