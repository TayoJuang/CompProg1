#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
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
#define INF -1
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
v64 z(v64 x) {
  ll n = x.size();
  v64 Z(n, 0);
  ll l = 0, r = 0;
  forsn(i, 1, n) {
    if (i <= r) {
      Z[i] = min(r - i + 1, Z[i - l]);
    }
    while ((i + Z[i]) < n && x[Z[i]] == x[i + Z[i]]) {
      Z[i] = Z[i] + 1;
    }
    if (i + Z[i] - 1 > r) {
      l = i;
      r = i + Z[i] - 1;
    }
  }
  return Z;
}
inline string moem_string() {
  string str;
  char c;
  while (true) {
    c = getchar_unlocked();
    if (c == EOF) return str;
    if (c != ' ' && c != '\n') break;
  }
  str.push_back(c);
  while ((c = getchar_unlocked()) != ' ' && c != '\n' && c != EOF) {
    str.push_back(c);
  }
  return str;
}
inline int moem_int() {
  int x = 0;
  unsigned int c;
  while ((c = getchar_unlocked()) == ' ' || c == '\n');
  do {
    x = x * 10 + (c - '0');
  } while ((c = getchar_unlocked()) >= '0' && c <= '9');
  return x;
}
class TrieNode {
 public:
  TrieNode* children[3];
  bool endOfWord;

  TrieNode() {
    endOfWord = false;
    forn(i, 3) { children[i] = nullptr; }
  }
};
class Trie {
 private:
  TrieNode* root;

 public:
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode* node = root;
    for (char c : word) {
      int index;
      if (c == '0') {
        index = 0;
      } else if (c == '1') {
        index = 1;
      } else if (c == '*') {
        index = 2;
      }
      if (!node->children[index]) {
        node->children[index] = new TrieNode();
      }
      node = node->children[index];
    }
    node->endOfWord = true;
  }
  bool search(string word) {
    TrieNode* node = root;
    for (char c : word) {
      int index;
      if (c == '0') {
        index = 0;
      } else if (c == '1') {
        index = 1;
      }
      if (node->children[2]) {  // if it has * as child return true as its a prefix
        return true;
      }
      if (!node->children[index]) {
        return false;
      }
      node = node->children[index];
    }
    if (node->children[2]) {  // if it has * as child return true as its a prefix
      return true;
    }
    return node->endOfWord;
  }
};
v32 bfs(vv32& graph, int start) {
  int n = graph.size();
  v32 dist(n, INF);
  dist[start] = 0;
  queue<int> q;
  q.push(start);

  int u;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (auto v : graph[u]) {
      if (dist[v] == INF) {
        dist[v] = dist[u] + 1;
        q.emplace(v);
      }
    }
  }
  return dist;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  int n, m, s1, s2, t1, t2, l1, l2;
  cin >> n >> m;
  cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
  s1 -= 1;
  s2 -= 1;
  t1 -= 1;
  t2 -= 1;
  vv32 adj(n);
  int u, v;
  forn(i, m) {
    cin >> u >> v;
    adj[u - 1].emplace_back(v - 1);
    adj[v - 1].emplace_back(u - 1);
  }
  vv32 dist(n, v32(n, INF));
  forn(i, n) { dist[i] = bfs(adj, i); }
  if (dist[s1][t1] > l1 || dist[s2][t2] > l2) {
    cout << -1 << ln;
    return 0;
  }
  int min_edges = dist[s1][t1] + dist[s2][t2];

  int d, path1, path2, total_edges;
  forn(u, n) {
    forn(v, n) {
      d = dist[u][v];

      path1 = dist[s1][u] + d + dist[v][t1];
      path2 = dist[s2][u] + d + dist[v][t2];

      if (path1 <= l1 && path2 <= l2) {
        total_edges = path1 + path2 - d;
        min_edges = min(total_edges, min_edges);
      }
      // path1 = dist[s1][v] + d + dist[u][t1];
      path2 = dist[s2][v] + d + dist[u][t2];

      if (path1 <= l1 && path2 <= l2) {
        total_edges = path1 + path2 - d;
        min_edges = min(total_edges, min_edges);
      }
    }
  }

  cout << min_edges << ln;

  return 0;
}