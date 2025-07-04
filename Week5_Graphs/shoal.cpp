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
  TrieNode *children[3];
  bool endOfWord;

  TrieNode() {
    endOfWord = false;
    forn(i, 3) { children[i] = nullptr; }
  }
};
class Trie {
 private:
  TrieNode *root;

 public:
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode *node = root;
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
    TrieNode *node = root;
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

void addUndirectedEdge(vv64 &adj, ll s, ll t) {
  adj[s].emplace_back(t);
  adj[t].emplace_back(s);
}

void dfsRec(vv64 &adj, vector<bool> &visited, ll s, vector<ll> &res) {
  visited[s] = true;
  res.emplace_back(s);
  for (auto i : adj[s]) {
    if (visited[i] == false) {
      dfsRec(adj, visited, i, res);
    }
  }
}

v64 DFS(vv64 &adj) {
  vector<bool> visited(adj.size(), false);
  vector<ll> res;
  dfsRec(adj, visited, 0, res);
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  ll n, m, a, b;
  cin >> n >> m;
  vv64 adj(n);
  forn(i, m) {
    cin >> a >> b;
    addUndirectedEdge(adj, a, b);
  }

  v64 res = DFS(adj);
  if (res.size() == n) {
    cout << "YES";
    return 0;
  } else {
    cout << "NO";
    return 0;
  }
  return 0;
}