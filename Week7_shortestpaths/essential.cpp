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
void dfs(vv64& graph, ll node, v64& with, v64& without) {  // dfs for tree dp
  for (auto& child : graph[node]) {
    dfs(graph, child, with, without);
    with[node] += without[child];
    without[node] += max(with[child], without[child]);
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

v64 dijkstra(vector<vector<tuple<ll, ll, ll>>>& graph, ll node) {
  ll n = graph.size();
  v64 dist(n, INF);
  // v64 pre(n, -1);
  dist[node] = 0;
  priority_queue<p64, vector<p64>, greater<p64>> pq;  // min heap
  pq.push({0, node});                                 // {distance, vertex}

  while (!pq.empty()) {
    ll d = pq.top().fi;
    ll u = pq.top().se;
    pq.pop();

    if (d > dist[u]) continue;

    for (auto& edge : graph[u]) {
      ll v = get<0>(edge);
      ll w = get<1>(edge);
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
        // pre[v] = u;
      }
    }
  }

  return dist;
}
vector<vector<tuple<ll, ll, ll>>> dijkstra_dist(vector<vector<tuple<ll, ll, ll>>>& graph, ll node, ll length) {
  ll n = graph.size();
  v64 dist(n, INF);
  vector<vector<tuple<ll, ll, ll>>> pre(n);
  dist[node] = 0;
  priority_queue<p64, vector<p64>, greater<p64>> pq;  // min heap
  pq.push({0, node});                                 // {distance, vertex}

  while (!pq.empty()) {
    ll d = pq.top().fi;
    ll u = pq.top().se;
    pq.pop();

    if (d > dist[u]) continue;

    for (auto& edge : graph[u]) {
      ll v = get<0>(edge);
      ll w = get<1>(edge);
      if (dist[v] >= dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
        if (dist[u] + w <= length && v != 1) {
          pre[v].emplace_back(u, get<2>(edge), get<1>(edge));
        }
      }
    }
  }

  return pre;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  ll t, u, v, n, m, w;
  string s;
  char c;
  cin >> n >> m;
  vector<vector<tuple<ll, ll, ll>>> graph(n + 1);  // node,weight,number
  vector<tuple<ll, ll, ll>> edges(m + 1);
  forn(i, m) {
    cin >> u >> v >> w;
    graph[u].emplace_back(v, w, i + 1);
    graph[v].emplace_back(u, w, i + 1);
    edges[i + 1] = {u, v, w};
  }
  v64 dist_1 = dijkstra(graph, 1);
  v64 dist_2 = dijkstra(graph, 2);
  // cout << dist[2] << ln;
  //  give out all paths that start at 1 and end at 2 with length of dist[2]
  // vector<vector<tuple<ll, ll, ll>>> pre = dijkstra_dist(graph, 1, dist[2]);
  // ll x = 2;
  set<ll> temp;
  ll shortest_dist = dist_1[2];
  forsn(i, 1, m + 1) {
    ll city1, city2, length;
    tie(city1, city2, length) = edges[i];
    if ((dist_1[city1] + length + dist_2[city2] == shortest_dist) || (dist_1[city2] + length + dist_2[city1] == shortest_dist)) {
      temp.insert(i);
    }
  }
  // queue<p64> q;
  // q.emplace(x, 0);
  // while (!q.empty()) {
  //   auto [x, ds] = q.front();
  //   q.pop();
  //   for (auto c : pre[x]) {
  //     if (ds + get<2>(c) <= dist[2]) {
  //       q.emplace(get<0>(c), ds + get<2>(c));
  //       temp.insert(get<1>(c));
  //     }
  //   }
  // }
  cout << temp.size() << ln;
  for (auto ele : temp) {
    cout << ele << " ";
  }
  return 0;
}