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

class TrieNode {
 public:
  TrieNode* children[2];
  bool endOfWord;
  bool isPrefix;
  TrieNode() {
    endOfWord = false;
    isPrefix = false;
    forn(i, 2) { children[i] = nullptr; }
  }
};

class Trie {
 private:
  TrieNode* root;

 public:
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    int n = word.size();
    TrieNode* node = root;
    for (char c : word) {
      if (c == '*') {
        node->isPrefix = true;
        break;
      }
      int index = (c - '0');
      if (!node->children[index]) {
        node->children[index] = new TrieNode();
      }
      node = node->children[index];
    }

    node->endOfWord = true;
  }
  bool search(string word) {
    int n = word.size();
    TrieNode* node = root;
    for (char c : word) {
      if (node->isPrefix) {  // if it has * as child return true as its a prefix
        return true;
      }
      int index = c - '0';

      if (!node->children[index]) {
        return false;
      }
      node = node->children[index];
    }

    return node->isPrefix || node->endOfWord;
  }
};

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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // cout.precision(10);
  Trie trie;
  string s;
  s.reserve(5 * 1e6);
  int n;
  n = moem_int();

  while (n--) {
    s = moem_string();
    trie.insert(s);
  }
  int m;
  m = moem_int();
  while (m--) {
    s = moem_string();
    if (trie.search(s)) {
      cout << "YES" << ln;
    } else {
      cout << "NO" << ln;
    }
  }
  return 0;
}