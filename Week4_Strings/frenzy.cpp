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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // cout.precision(10);
  string s;
  cin >> s;
  ll n = s.size();

  v32 last_char(26, -1);
  forn(i, n) { last_char[s[i] - 'a'] = i; }
  vector<bool> used(26, false);
  string res;
  char c;
  forn(i, n) {
    c = s[i];
    if (used[c - 'a']) continue;
    while (!res.empty() && res.back() < c && last_char[res.back() - 'a'] > i) {
      used[res.back() - 'a'] = false;
      res.pop_back();
    }
    res.push_back(c);
    used[c - 'a'] = true;
  }
  cout << res << ln;
  return 0;
}