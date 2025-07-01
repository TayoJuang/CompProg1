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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  ll t, u, v, n, m, x, small_x, big_x;
  // v64 xs;
  string s;
  char c;
  cin >> t;
  forn(zz, t) {
    cin >> n;
    cin >> m;
    vector<tuple<ll, ll, ll>> a;
    forn(i, n) {
      forn(j, m) {
        ll ele;
        cin >> ele;
        a.emplace_back(ele, i, j);
      }
    }
    sort(a.begin(), a.end(), [](const auto& a, const auto& b) { return get<0>(a) > get<0>(b); });
    if (get<0>(a[0]) > get<0>(a[1]))
      cout << get<0>(a[0]) - 1 << ln;
    else {
      bool blub = false;
      ll row = INF, col = INF;
      if (get<1>(a[0]) == get<1>(a[1])) row = get<1>(a[0]);
      if (get<2>(a[0]) == get<2>(a[1])) col = get<2>(a[0]);
      ll u = 2;
      while (u < min(n + m, n * m - 1) && get<0>(a[0]) == get<0>(a[u])) {
        if (row == INF && col == INF) {
          if (get<1>(a[0]) == get<1>(a[u]) || get<2>(a[u]) == get<2>(a[1])) {
            row = get<1>(a[0]);
            col = get<2>(a[1]);
          } else if (get<1>(a[u]) == get<1>(a[1]) || get<2>(a[0]) == get<2>(a[u])) {
            row = get<1>(a[1]);
            col = get<2>(a[0]);
          } else {
            cout << get<0>(a[u]) << ln;
            blub = true;
            break;
          }
          u++;
        } else if (row == INF && get<2>(a[u]) != col) {
          row = get<1>(a[u]);
          u++;
        } else if (col == INF && get<1>(a[u]) != row) {
          col = get<2>(a[u]);
          u++;
        } else {
          if (get<1>(a[u]) == row || get<2>(a[u]) == col) {
            u++;
          } else {
            cout << get<0>(a[u]) << ln;
            blub = true;
            break;
          }
        }
      }
      if (!blub) {
        if (get<0>(a[0]) == get<0>(a[u]) && u != n * m - 1) {
          cout << get<0>(a[u]) << ln;
        } else {
          cout << get<0>(a[0]) - 1 << ln;
        }
      }
    }
  }
  return 0;
}