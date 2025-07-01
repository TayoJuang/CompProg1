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
class union_find {
 private:
  v64 parents;
  vp64 size_parent;
  v64 children;          // parents inverse, parent points to a child, child ponits to next, -1 if no children
  v64 inverse_children;  // child points to the one its being pointed at in cihldern
  v64 tails;

 public:
  union_find(ll n) {
    parents = v64(n + 1);
    size_parent = vp64(n + 1);
    children = v64(n + 1, -1);
    inverse_children = v64(n + 1, -1);  //-1 means that it isnt being pointed at from anywrere? :pray:
    tails = v64(n + 1);
    forn(i, n + 1) {
      parents[i] = i;
      size_parent[i] = {1, i};
      tails[i] = i;
    }
  }
  ll u_find(ll child) {
    if (parents[child] != child) {
      parents[child] = u_find(parents[child]);
      return parents[child];
    } else {
      return child;
    }
  }

  void u_union_set(ll p, ll q) {
    ll rp = u_find(p);
    ll rq = u_find(q);
    if (rp == rq) {
      return;
    }
    ll tail_rp = tails[rp];
    children[tail_rp] = rq;
    inverse_children[rq] = tail_rp;
    tails[rp] = tails[rq];
    parents[rq] = rp;

    size_parent[rp].fi += size_parent[rq].first;
    size_parent[rp].se += size_parent[rq].se;
    size_parent[rq] = {0, 0};
  }

  void u_move(ll p, ll q) {
    ll rp = u_find(p);
    ll rq = u_find(q);
    if (rp == rq) {
      return;
    }

    ll pred = inverse_children[p];
    ll succ = children[p];
    if (pred != -1) {
      children[pred] = succ;
    }
    if (succ != -1) {
      inverse_children[succ] = pred;
      parents[succ] = pred;
    }

    if (p == rp) {  // p is head
      ll new_rep = succ;
      if (new_rep != -1) {  // we have a child
        size_parent[new_rep] = size_parent[rp];
        size_parent[new_rep].fi -= 1;
        size_parent[new_rep].se -= p;
        ll curr_child = new_rep;
        while (curr_child != -1) {
          parents[curr_child] = new_rep;
          curr_child = children[curr_child];
        }
        inverse_children[new_rep] = -1;
        tails[new_rep] = tails[rp];
        tails[rp] = p;  // clean slate for rp
      }
      size_parent[p] = {0, 0};
    } else {
      size_parent[rp].fi -= 1;
      size_parent[rp].se -= p;
    }
    // fix old
    if (tails[rp] == p) {  // so if p was tail then we need to change things
      if (pred != -1) {    // if p was not head
        tails[rp] = pred;  // we can move the tail the one back
      } else {
        if (succ != -1) {  // if p was not the last covered already
        } else {
          tails[rp] = rp;  // p was all alone
        }
      }
    }

    parents[p] = rq;
    ll old = children[rq];
    children[rq] = p;
    inverse_children[p] = rq;
    children[p] = old;
    if (old != -1) {
      inverse_children[old] = p;
    }

    size_parent[rq].fi += 1;
    size_parent[rq].se += p;
    if (children[p] == -1) {  // if p is the final now
      tails[rq] = p;
    }
    tails[p] = p;  // reset p
  }

  p64 u_size(ll p) { return size_parent[u_find(p)]; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  ll n, m, cmd, p, q;
  cin >> n >> m;
  vector<set<ll>> sets(n + 1);
  vector<ll> sums(n + 1);
  vector<ll> set_of(n + 1);
  // union_find u(n);
  //  use sets have a reference array from each number to a set
  //  move/union sets based off of smaller into larger
  //  somehow store the size and sum of values

  forn(i, n + 1) {
    sets[i].insert(i);
    sums[i] = i;
    set_of[i] = i;
  }
  forn(i, m) {
    cin >> cmd >> p;
    if (cmd == 3) {
      // print p;
      ll p_set = set_of[p];
      cout << sets[p_set].size() << " " << sums[p_set] << ln;
    } else {
      cin >> q;
      ll p_set = set_of[p];
      ll q_set = set_of[q];
      if (cmd == 1) {
        // union p and q;
        // smaller into larger
        if (p_set == q_set) continue;
        if (sets[p_set].size() <= sets[q_set].size()) {
          for (auto elem : sets[p_set]) {
            sets[q_set].insert(elem);
            set_of[elem] = q_set;
          }
          sums[q_set] += sums[p_set];
          sets[p_set].clear();
          sums[p_set] = 0;
        } else {
          for (auto elem : sets[q_set]) {
            sets[p_set].insert(elem);
            set_of[elem] = p_set;
          }
          sums[p_set] += sums[q_set];
          sets[q_set].clear();
          sums[q_set] = 0;
        }
      } else if (cmd == 2) {
        // move p to q;
        if (p_set == q_set) continue;
        sets[p_set].erase(p);
        sums[p_set] -= p;

        sets[q_set].insert(p);
        sums[q_set] += p;

        set_of[p] = q_set;
      }
    }
  }
  return 0;
}