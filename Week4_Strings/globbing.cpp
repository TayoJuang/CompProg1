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
  cout.precision(10);
  ll t;
  cin >> t;
  cin.ignore();
  string s, p, p1, p2, match;
  vector<ll> res, res1, res2;
  while (t--) {
    bool is_plus = true;
    getline(cin, p);
    getline(cin, s);
    ll pos = p.find('+');
    if (pos == -1) {
      is_plus = !is_plus;
      pos = p.find('*');
    }
    if (pos == -1) {
      if (p.size() < s.size()) {
        cout << "NO" << ln;
        continue;
      }
      match = p;
      match += '#';
      match.append(s);
      res = prefix(match);
      if (res.back() == p.size()) {
        cout << "YES" << "\n";
      } else {
        cout << "NO" << "\n";
      }
      continue;
    }
    p1 = p.substr(0, pos);
    p2 = p.substr(pos + 1);

    string match1 = p1;
    string match2 = p2;
    match1 += '#';
    match2 += '#';
    match1.append(s);
    match2.append(s);
    res1 = prefix(match1);
    res2 = prefix(match2);

    ll a_match1 = -1;
    ll a_match2 = -1;
    forn(i, res1.size()) {
      if (res1[i] == p1.size()) {
        a_match1 = i - p1.size();
        break;
      }
    }
    for (ll i = res2.size() - 1; i >= 0; i--) {
      if (res2[i] == p2.size()) {
        a_match2 = i - (2 * p2.size()) + 1;
        break;
      }
    }
    if (is_plus && a_match1 + 1 < a_match2 && (a_match1 != -1 && a_match2 != -1)) {
      cout << "YES" << ln;
      continue;
    } else if (!is_plus && a_match1 < a_match2 && (a_match1 != -1 && a_match2 != -1)) {
      cout << "YES" << ln;
      continue;
    } else {
      cout << "NO" << ln;
    }
  }
  return 0;
}