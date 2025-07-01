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
vector<int> prefix(string x) {
  int n = x.size();
  vector<int> P(n);
  P[0] = 0;
  int j;
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
  while ((c = getchar_unlocked()) == ' ' || c == '\n');
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
  int n, m;
  // cin >> n >> m;
  n = moem_int();
  m = moem_int();
  int n1 = n;
  int m1 = m;
  // cin.ignore();
  string s, p;
  string a;
  while (n1--) {
    // cin >> a;
    a = moem_string();
    s += a;
  }
  while (m1--) {
    // cin >> a;
    a = moem_string();
    p += a;
  }
  // just in case
  /*if (p == s) {
    cout << "YES" << ln;
    return 0;
  }*/
  if (m > n) {
    swap(s, p);
  }
  string match = p;
  match += '#';
  match.append(s);
  match.append(s);
  /*123#123*/
  vector<int> res1 = prefix(match);
  int start_idx = 0;
  forn(i, res1.size()) {
    if (res1[i] == p.size()) {
      start_idx = i - (2 * p.size());
      break;
    }
  } /*1 2 3 # 2 3 1 2 3 1 -> 1 2 3 1 2 3*/

  string bettermatch = s.substr(start_idx) + s.substr(0, start_idx) + s.substr(start_idx) + s.substr(0, start_idx);
  forn(i, bettermatch.size()) {
    if (bettermatch[i] == p[i % p.size()]) {
      continue;
    } else {
      cout << "NO" << ln;
      return 0;
    }
  }
  cout << "YES" << ln;

  // string bettermatch = p;
  // bettermatch += '#';
  // bettermatch.append(s.substr(start_idx));
  // bettermatch.append(s.substr(0, start_idx));
  // bettermatch.append(s.substr(start_idx));
  // bettermatch.append(s.substr(0, start_idx));

  // vector<ll> real_res = prefix(bettermatch);
  // // counter method
  //
  // ll counter = 0;
  // for (ll i = p.size() + p.size(); i < real_res.size(); i += p.size()) {
  //   if (real_res[i] == p.size()) {
  //     counter++;
  //   } else {
  //     cout << "NO" << ln;
  //     return 0;
  //   }
  // }
  // if (counter == ((2 * s.size()) / p.size()) && ((real_res[real_res.size() - 1] >= (s.size() % p.size())))) {
  //   cout << "YES" << ln;
  // } else {
  //   cout << "NO" << ln;
  // }
  return 0;
}