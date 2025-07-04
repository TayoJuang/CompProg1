#include <bits/stdc++.h>  // includes all; gcc only

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) begin(a), end(a)

using namespace std;
using ll = long long;

ll fac(int a) {
  if (a <= 1) return 1;
  return fac(a - 1) * a;
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // cout.precision(10);
  //  content
  int t, n, p;

  t = moem_int();
  vector<pair<int, int>> pairs(t);
  for (int i = 0; i < t; i++) {
    n = moem_int();
    p = moem_int();
    // cout << (fac(n) / fac(p)) % 998244353 << "\n";
    pairs[i] = {n, p};
  }
  int maxP1 = 0;
  int maxn1 = 0;
  for (int j = 0; j < t; j++) {
    if (maxP1 < get<1>(pairs[j])) {
      maxP1 = get<1>(pairs[j]);
    }
    if (maxn1 < get<0>(pairs[j])) {
      maxn1 = get<0>(pairs[j]);
    }
  }
  vector<vector<ll>> hedge(maxP1 + 1, vector<ll>(maxn1 + 1, 1));  // fill everything with ones for now

  for (ll p1 = 2; p1 < maxP1 + 1; p1++) {
    for (ll n1 = p1 + 1; n1 < maxn1 + 1; n1++) {
      hedge[p1][n1] = (((p1 * hedge[p1][n1 - 1]) % 998244353) + (hedge[p1 - 1][n1 - 1] * (n1 - (p1 - 1))) % 998244353) % 998244353;
    }
  }

  for (int i = 0; i < t; i++) {
    cout << hedge[get<1>(pairs[i])][get<0>(pairs[i])] % 998244353 << "\n";
  }
}
