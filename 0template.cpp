#include <bits/stdc++.h>  // includes all; gcc only

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) begin(a), end(a)

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);

  // content
  int N, row;

  cin >> N;
  vector<int> coins(N);
  vector<int> dp(N + 1);
  dp[0] = 0;
  for (int i = 0; i < N; i++) {
    cin >> row;
    coins[i] = row;
  }
  ll sum = 0;
  //(0) 5 4 9 2
  // a for loo

  rep(i, N) { dp[i + 1] = max(dp[i], dp[i - 1] + coins[i]); }
  for (auto d : dp) {
    cout << d << " ";
  }
}
