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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // cout.precision(10);
  int n, m, k;
  n = moem_int();
  m = moem_int();
  k = moem_int();
  // cin >> n >> m >> k;
  map<string, int> groceries;
  string g;
  forn(i, k) {
    // cin >> g;
    g = moem_string();
    groceries[g] = i;
  }
  vv32 graph(n + 1);
  int u, v;
  forn(i, m) {
    // cin >> u >> v;
    u = moem_int();
    v = moem_int();
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  int amt;
  vector<vp32> offers(n + 1);
  string id;
  int t;
  forsn(i, 1, n + 1) {
    // cin >> amt;
    amt = moem_int();
    forn(j, amt) {
      // cin >> id >> t;
      id = moem_string();
      t = moem_int();
      auto it = groceries.find(id);
      if (it != groceries.end()) {
        offers[i].emplace_back(it->second, t);
      }
    }
  }
  // vector<vector<bool>> visited(n + 1, vector<bool>(1 << k, false));
  bool visited[1001][1024];
  memset(visited, false, sizeof(visited));
  int start_mask = 0;
  for (auto groc : offers[1]) {
    auto [item, T] = groc;
    if (T > 0) start_mask = start_mask | (1 << item);
  }
  // node, items found, distnace
  queue<tuple<int, int, int>> q;
  q.emplace(1, start_mask, 0);
  visited[1][start_mask] = true;
  int newdist, newmask;
  while (!q.empty()) {
    auto [u, mask, d] = q.front();
    q.pop();

    if (u == 1 && mask == (1 << k) - 1) {
      cout << d;
      return 0;
    }
    for (int v : graph[u]) {
      newdist = d + 1;
      newmask = mask;

      for (p32 groc : offers[v]) {
        auto [item, T] = groc;
        if (newdist < T) newmask |= (1 << item);
      }

      if (!visited[v][newmask]) {
        visited[v][newmask] = true;
        q.emplace(v, newmask, newdist);
      }
    }
  }
  cout << -1;
  return 0;
}