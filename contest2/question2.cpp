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

v64 prefix(string x) {  // prefix function
  ll n = x.size();
  v64 P(n);
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
v64 z(v64 x) {  // z function, uses a v64 as input, change v64 to string if you want to use it with strings
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
ll dfs(ll node, vector<vector<pair<ll, bool>>>& un_graph, vector<bool>& visited) {  // dfs for tree dp

  if (un_graph[node].size() <= 1 && node != 1) {
    visited[node] = true;
    return 0;
  } else {
    ll sum = 0;
    for (auto& child : un_graph[node]) {
      if (visited[child.fi] == false) {
        visited[child.fi] = true;
        sum += dfs(child.fi, un_graph, visited);

        if (child.se == true) {
          sum += 1;
        }
      }
    }
    return sum;
  }

  // cout << node << ' ' << with[node] << ' ' << without[node] << ln;
}

void bfs(const vv64& graph, ll node, vv64& dist) {
  queue<ll> q;
  dist[node][node] = 0;
  forn(i, node) dist[node][i] = dist[i][node];
  ll curr;
  while (!q.empty()) {
    curr = q.front();
    q.pop();
    for (auto& child : graph[curr]) {
      if (dist[node][child] == INF) {
        dist[node][child] = dist[node][curr] + 1;
        q.push(child);
      }
    }
  }
}

v64 topo_sort(vv64& graph) {
  ll n = graph.size();
  v64 e_in(n, 0);
  queue<ll> queue;
  v64 sorting;
  sorting.reserve(n);
  ll node;
  forn(i, n) for (auto& child : graph[i]) e_in[child]++;
  forn(i, n) if (e_in[i] == 0) queue.push(i);
  while (!queue.empty()) {
    node = queue.front();
    queue.pop();
    sorting.pb(node);
    for (auto& child : graph[node]) {
      e_in[child]--;
      if (e_in[child] == 0) queue.push(child);
    }
  }
  if (sorting.size() == n) return sorting;
  return {-1};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  ll t, u, v, n, m;
  string s;
  char c;
  cin >> n;

  vector<vector<pair<ll, bool>>> un_graph(n + 1);
  vector<bool> visited(n + 1, false);
  forn(i, n - 1) {
    cin >> u >> v;
    un_graph[u].emplace_back(v, true);
    un_graph[v].emplace_back(u, false);
  }
  visited[1] = true;
  cout << dfs(1, un_graph, visited);
  return 0;
}