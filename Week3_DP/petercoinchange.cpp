#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  ll t, x, c;
  pair<ll, ll> curr_pair;
  cin >> t;
  while (t--) {
    cin >> x >> c;
    vector<ll> values(c);
    for (ll i = 0; i < c; i++) cin >> values[i];
    vector<ll> min_coins(x + values[c - 1] + 1);
    for (int i = 0; i <= x + values[c - 1]; i++) min_coins[i] = i;
    for (int i = 0; i < c; i++) {
      for (int j = 0; j <= x + values[c - 1]; j++)
        if (j >= values[i]) min_coins[j] = min(min_coins[j], 1 + min_coins[j - values[i]]);
      for (int j = x + values[c - 1]; j >= 0; j--)
        if (j + values[i] <= x + values[c - 1]) min_coins[j] = min(min_coins[j], 1 + min_coins[j + values[i]]);
    }
    cout << min_coins[x] << "\n";
  }
  return 0;
}