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

v64 prefix(string x) {
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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  ll k, c;
  cin >> k >> c;
  v64 rev_blocks(k);
  ll a = -1;
  forn(i, k) {
    cin >> a;
    rev_blocks[i] = a;
  }
  v64 blocks = rev_blocks;
  reverse(rev_blocks.begin(), rev_blocks.end());
  v64 to_compare = blocks;
  to_compare.emplace_back(0);
  to_compare.insert(to_compare.end(), rev_blocks.begin(), rev_blocks.end());
  v64 match = z(to_compare);
  v64 ans;
  ll m_size = match.size();
  // for (ll i = match.size() - 1; i >= blocks.size(); i--) {
  //   ll x = match.size() - i;
  //   if (match[i] == match.size() - i && ((i - 1) % 2) == 0) {
  //     ans.emplace_back(k - (match.size() - i) / 2);
  //   }
  // }
  for (ll i = blocks.size() + 1; i < m_size; i++) {
    if (match[i] == m_size - i && ((i - 1) % 2) == 0) {
      ans.emplace_back(k - (m_size - i) / 2);
    }
  }
  ans.emplace_back(k);
  for (auto a : ans) {
    cout << a << " ";
  }
  return 0;
}