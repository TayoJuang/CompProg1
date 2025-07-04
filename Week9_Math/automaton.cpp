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

vv64 multiply(vv64 m, vv64 n) {
  ll mod = 998244353;
  vv64 result(16, v64(16, 0));
  forn(i, 16) {
    forn(j, 16) {
      forn(k, 16) {
        result[i][j] += (m[i][k] * n[k][j]) % mod;
        result[i][j] = result[i][j] % mod;
      }
    }
  }
  return result;
}

vv64 flowerPower(vv64 m, ll i) {
  ll mod = 998244353;
  if (i == 1)
    return m;
  else if (i % 2 == 1)
    return multiply(flowerPower(multiply(m, m), i / 2), m);
  else
    return flowerPower(multiply(m, m), i / 2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  ll mod = 998244353;
  ll t, u, v, n, m;
  string s1, s2, b1, b2, b3, b4;
  char c;
  cin >> t;
  cin >> s1 >> s2;
  v64 start(16, 0);
  vv64 M(16, v64(16, 0));
  v64 count(16, 0);
  if (s1 == "##" && s2 == "##") {
    start[0] = 1;
  } else if (s1 == "##" && s2 == "#.") {
    start[1] = 1;
  } else if (s1 == "##" && s2 == ".#") {
    start[2] = 1;
  } else if (s1 == "##" && s2 == "..") {
    start[3] = 1;
  } else if (s1 == "#." && s2 == "##") {
    start[4] = 1;
  } else if (s1 == "#." && s2 == "#.") {
    start[5] = 1;
  } else if (s1 == "#." && s2 == ".#") {
    start[6] = 1;
  } else if (s1 == "#." && s2 == "..") {
    start[7] = 1;
  } else if (s1 == ".#" && s2 == "##") {
    start[8] = 1;
  } else if (s1 == ".#" && s2 == "#.") {
    start[9] = 1;
  } else if (s1 == ".#" && s2 == ".#") {
    start[10] = 1;
  } else if (s1 == ".#" && s2 == "..") {
    start[11] = 1;
  } else if (s1 == ".." && s2 == "##") {
    start[12] = 1;
  } else if (s1 == ".." && s2 == "#.") {
    start[13] = 1;
  } else if (s1 == ".." && s2 == ".#") {
    start[14] = 1;
  } else if (s1 == ".." && s2 == "..") {
    start[15] = 1;
  }
  count[0] = 4;
  count[1] = 3;
  count[2] = 3;
  count[3] = 2;
  count[4] = 3;
  count[5] = 2;
  count[6] = 2;
  count[7] = 1;
  count[8] = 3;
  count[9] = 2;
  count[10] = 2;
  count[11] = 1;
  count[12] = 2;
  count[13] = 1;
  count[14] = 1;
  count[15] = 0;

  forn(i, 16) {
    ll row = -1;
    cin >> s1 >> s2;
    if (s1 == "##" && s2 == "##") {
      row = 0;
    } else if (s1 == "##" && s2 == "#.") {
      row = 1;
    } else if (s1 == "##" && s2 == ".#") {
      row = 2;
    } else if (s1 == "##" && s2 == "..") {
      row = 3;
    } else if (s1 == "#." && s2 == "##") {
      row = 4;
    } else if (s1 == "#." && s2 == "#.") {
      row = 5;
    } else if (s1 == "#." && s2 == ".#") {
      row = 6;
    } else if (s1 == "#." && s2 == "..") {
      row = 7;
    } else if (s1 == ".#" && s2 == "##") {
      row = 8;
    } else if (s1 == ".#" && s2 == "#.") {
      row = 9;
    } else if (s1 == ".#" && s2 == ".#") {
      row = 10;
    } else if (s1 == ".#" && s2 == "..") {
      row = 11;
    } else if (s1 == ".." && s2 == "##") {
      row = 12;
    } else if (s1 == ".." && s2 == "#.") {
      row = 13;
    } else if (s1 == ".." && s2 == ".#") {
      row = 14;
    } else if (s1 == ".." && s2 == "..") {
      row = 15;
    }

    cin >> b1 >> b2 >> b3 >> b4;
    for (ll j = 0; j <= 2; j += 2) {
      ll col = -1;
      s1 = b1.substr(j, 2);
      s2 = b2.substr(j, 2);
      if (s1 == "##" && s2 == "##") {
        col = 0;
      } else if (s1 == "##" && s2 == "#.") {
        col = 1;
      } else if (s1 == "##" && s2 == ".#") {
        col = 2;
      } else if (s1 == "##" && s2 == "..") {
        col = 3;
      } else if (s1 == "#." && s2 == "##") {
        col = 4;
      } else if (s1 == "#." && s2 == "#.") {
        col = 5;
      } else if (s1 == "#." && s2 == ".#") {
        col = 6;
      } else if (s1 == "#." && s2 == "..") {
        col = 7;
      } else if (s1 == ".#" && s2 == "##") {
        col = 8;
      } else if (s1 == ".#" && s2 == "#.") {
        col = 9;
      } else if (s1 == ".#" && s2 == ".#") {
        col = 10;
      } else if (s1 == ".#" && s2 == "..") {
        col = 11;
      } else if (s1 == ".." && s2 == "##") {
        col = 12;
      } else if (s1 == ".." && s2 == "#.") {
        col = 13;
      } else if (s1 == ".." && s2 == ".#") {
        col = 14;
      } else if (s1 == ".." && s2 == "..") {
        col = 15;
      }
      M[row][col] += 1;
      s1 = b3.substr(j, 2);
      s2 = b4.substr(j, 2);
      if (s1 == "##" && s2 == "##") {
        col = 0;
      } else if (s1 == "##" && s2 == "#.") {
        col = 1;
      } else if (s1 == "##" && s2 == ".#") {
        col = 2;
      } else if (s1 == "##" && s2 == "..") {
        col = 3;
      } else if (s1 == "#." && s2 == "##") {
        col = 4;
      } else if (s1 == "#." && s2 == "#.") {
        col = 5;
      } else if (s1 == "#." && s2 == ".#") {
        col = 6;
      } else if (s1 == "#." && s2 == "..") {
        col = 7;
      } else if (s1 == ".#" && s2 == "##") {
        col = 8;
      } else if (s1 == ".#" && s2 == "#.") {
        col = 9;
      } else if (s1 == ".#" && s2 == ".#") {
        col = 10;
      } else if (s1 == ".#" && s2 == "..") {
        col = 11;
      } else if (s1 == ".." && s2 == "##") {
        col = 12;
      } else if (s1 == ".." && s2 == "#.") {
        col = 13;
      } else if (s1 == ".." && s2 == ".#") {
        col = 14;
      } else if (s1 == ".." && s2 == "..") {
        col = 15;
      }
      M[row][col] += 1;
    }
  }
  M = flowerPower(M, t);

  auto it = find(start.begin(), start.end(), 1);
  ll idx = it - start.begin();
  v64 res = M[idx];
  // count blacks
  ll total = 0;
  forn(i, 16) {
    ll between = res[i];
    total += (count[i] * between) % mod;
  }
  total = total % mod;
  cout << total;
  return 0;
}
