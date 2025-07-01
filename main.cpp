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

vector<ll> prefix(string x) {
  ll n = x.size();
  vector<ll> P(n);
  P[0] = 0;
  ll j;
  forsn(i, 1, n) {
    j = P[i - 1];
    while (j > 0 && x[i] != x[j]) {
      j = P[j - 1];
    }
    if (x[i] == x[j]) {
      j += 1;
    }
    P[i] = j;
  }
  return P;
}

void bfs(vv64 &graph, ll node, v64 &a, v64 &t) {
  queue<tuple<ll, ll, ll>> q;
  q.emplace(node, -1, -1);
  tuple<ll, ll, ll> curr;

  while (!q.empty()) {
    curr = q.front();
    q.pop();
    if (get<0>(curr) == 0 || get<1>(curr) == 0) {
      t[get<0>(curr)] = a[get<0>(curr)];
      forn(i, graph[get<0>(curr)].size()) {
        if (graph[get<0>(curr)][i] != get<1>(curr)) q.emplace(graph[get<0>(curr)][i], get<0>(curr), get<1>(curr));
      }
    } else {
      t[get<0>(curr)] = max(a[get<0>(curr)], t[get<2>(curr)] - a[get<1>(curr)] + a[get<0>(curr)]);
      forn(i, graph[get<0>(curr)].size()) {
        if (graph[get<0>(curr)][i] != get<1>(curr)) q.emplace(graph[get<0>(curr)][i], get<0>(curr), get<1>(curr));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // cout.precision(10);
  ll t;
  cin >> t;
  string s;
  ll n;
  while (t--) {
    cin >> n;
    vector<v64> graph(n);
    v64 a(n);
    forn(i, n) cin >> a[i];
    ll u, v;
    forn(i, n - 1) {
      cin >> u >> v;
      graph[u - 1].pb(v - 1);
      graph[v - 1].pb(u - 1);
    }
    v64 t(n, 0);
    bfs(graph, 0, a, t);
    forn(i, n) cout << t[i] << ' ';
    cout << ln;
  }

  return 0;
}