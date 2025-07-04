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
void addDirectedEdge(vv64 &adj, ll s, ll t) { adj[s].emplace_back(t); }
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

v64 TopoSort(vv64 &adj_inc, vv64 &adj) {
  v64 L;
  ll n = adj.size();
  v64 count(n, 0);
  for (ll i = 0; i < n; i++) {
    for (auto j : adj[i]) {
      count[i]++;
    }
  }
  queue<ll> nodes;
  forn(i, n) {
    if (count[i] == 0) {
      nodes.push(i);
    }
  }
  if (nodes.size() == 0) {
    L.emplace_back(-2);  // cycles?
    return L;
  } else if (nodes.size() > 1) {
    L.emplace_back(-1);  // more than one starting point
    return L;
  }
  while (!nodes.empty()) {
    ll top = nodes.front();
    nodes.pop();
    ll nodes_size = nodes.size();
    L.emplace_back(top);
    for (auto i : adj_inc[top]) {
      count[i]--;
      if (count[i] == 0) {
        nodes.push(i);
      }
    }
    if (nodes_size + 1 < nodes.size()) {
      L.emplace_back(-1);  // atl two possible paths now,
      return L;
    }
  }
  return L;
}

p32 BFS(vv32 &board, int board_sizew, int board_sizeh, p32 node, vector<vector<p32>> &mem, vv32 &distance) {
  vp32 knightMoves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

  queue<p32> q;
  q.emplace(node);
  distance[node.fi][node.se] = 0;
  p32 curr;
  int row, col;
  while (!q.empty()) {
    curr = q.front();
    q.pop();

    for (auto move : knightMoves) {
      row = curr.fi + move.fi;
      col = curr.se + move.se;
      if (row >= 0 && row < board_sizeh && col >= 0 && col < board_sizew && board[row][col] != 2 && distance[row][col] == INF) {
        mem[row][col] = curr;
        distance[row][col] = distance[curr.fi][curr.se] + 1;
        if (board[row][col] == 1) return {row, col};
        q.emplace(row, col);
      }
    }
  }
  return {-1, -1};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  ll w, h;
  cin >> w >> h;
  vv32 board(h, v32(w, 0));
  string line;
  p64 start;
  forn(i, h) {
    cin >> line;
    forn(j, w) {
      if (line[j] == 'N')
        board[h - 1 - i][j] = 1;
      else if (line[j] == 'k')
        start = {h - 1 - i, j};
      else if (line[j] == 'K' || line[j] == 'Q' || line[j] == 'B' || line[j] == 'R' || line[j] == 'P')
        board[h - 1 - i][j] = 2;
    }
  }
  vv32 distance(h, v32(w, INF));
  vector<vp32> mem(h, vp32(w));
  p32 knight = BFS(board, w, h, start, mem, distance);
  if (knight.fi == -1)
    cout << "Resign" << ln;
  else {
    int len = distance[knight.fi][knight.se];
    cout << "Checkmate in " << len << ln;
    forn(i, len) {
      cout << knight.fi + 1 << ' ' << knight.se + 1 << ' ' << mem[knight.fi][knight.se].fi + 1 << ' ' << mem[knight.fi][knight.se].se + 1 << ln;
      knight = mem[knight.fi][knight.se];
    }
  }
  return 0;
}