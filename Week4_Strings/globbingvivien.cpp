#include <bits/stdc++.h>  // includes all; gcc only

#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <vector>

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
  bool endofword;

  TrieNode() {
    endofword = false;
    forn(i, 3) children[i] = nullptr;
  }
};

class Trie {
 private:
  TrieNode* root{};

 public:
  Trie() { root = new TrieNode(); }

  int index(char c) {
    switch (c) {
      case '0':
        return 0;
      case '1':
        return 1;
      case '*':
        return 2;
    }
    return 0;
  }

  void insert(string word) {
    TrieNode* node = root;
    for (char c : word) {
      int idx = index(c);
      if (node->children[idx] == nullptr) node->children[idx] = new TrieNode();
      node = node->children[idx];
    }
    node->endofword = true;
  }

  bool contains(string word) {
    TrieNode* node = root;
    for (char c : word) {
      int idx = index(c);
      if (node->children[2] != nullptr) return true;
      if (node->children[idx] == nullptr) return false;
      node = node->children[idx];
    }
    if (node->children[2] != nullptr || node->endofword) return true;
    return false;
  }

  ~Trie() { rec_delete(root); }

  void rec_delete(TrieNode* node) {
    if (node == nullptr) return;
    forn(i, 3) rec_delete(node->children[i]);
    delete node;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);

  // content
  ll t;
  cin >> t;
  cin.ignore();
  string pa, s;
  forn(i, t) {
    getline(cin, pa);
    getline(cin, s);
    int lp = pa.size(), ls = s.length();
    int j = 0;
    while (j < min(lp, ls) && pa[j] == s[j]) j++;
    if (j == max(lp, ls))
      cout << "Yes" << ln;
    else if (j == min(lp, ls) && !(j == ls && pa[j] == '*'))
      cout << "No" << ln;
    else {
      int k = 0;
      while (k < min(lp, ls) && pa[lp - 1 - k] == s[ls - 1 - k]) k++;
      if (j == lp - 1 - k && ls - 1 - k - j >= -1 && pa[j] == '*')
        cout << "Yes" << ln;
      else if (j == lp - 1 - k && ls - 1 - k - j >= 0)
        cout << "Yes" << ln;
      else
        cout << "No" << ln;
    }
  }

  return 0;
}
