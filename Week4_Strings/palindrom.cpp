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
  string s;
  s = moem_string();
  // cin >> s;
  int n = s.size();
  // vv64 dp(n, vector<ll>(n));
  int dp[2000][2000];
  forn(i, n) { dp[i][i] = 0; }

  for (int len = 2; len <= n; len++) {
    for (int i = 0; i <= n - len; i++) {
      int j = i + len - 1;
      if (i == j) {
        continue;
      }
      if (s[i] == s[j]) {
        dp[i][j] = dp[i + 1][j - 1];
        //   } else if (s[i] != s[j] && (abs(j - i) + 1) % 2 == 0) {  // even
        //     dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
        //   } else if (s[i] != s[j] && (abs(j - i) + 1) % 2 == 1) {  // odd
      } else {
        dp[i][j] = 1 + min(min(dp[i + 1][j], dp[i][j - 1]), dp[i + 1][j - 1]);
      }
    }
  }
  cout << dp[0][n - 1];
  return 0;
}