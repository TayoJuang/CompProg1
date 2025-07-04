#include <bits/stdc++.h>  // includes all; gcc only

#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <vector>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) begin(a), end(a)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<vector<ll>> vv64;

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
  cout.precision(10);

  // content
  ll n;  // = moem_int();
  cin >> n;
  vector<ll> positions;
  positions.resize(n);
  vector<ll> cost;
  cost.resize(n);
  rep(i, n) { cin >> positions[i]; }
  rep(i, n) { cin >> cost[i]; }
  vector<ll> M(n, 0);
  ll cost_of_teardown, cost_of_min_tower, min_tower, changed_gap;
  // initialize diagonal
  // Price assuming that i is the last tower placed
  // Instead of looking at the tower before, we find the min value before, take that as the last tower
  // Recalculate costs based off of that

  // Prefix of positions
  /*v64 pos(n);
  pos[0] = 0;
  for (ll i = 1; i < n; i++) {
    pos[i] = pos[i - 1] + positions[i] - positions[0];
  }*/
  cost_of_teardown = cost[0];
  for (ll i = 1; i < n; i++) {
    cost_of_teardown += positions[i] - positions[0];
  }
  M[0] = {cost_of_teardown};
  ll point = 0;
  for (ll j = 1; j < n; ++j) {
    min_tower = LLONG_MAX;
    point = j - 1;  // left most tower closer to j than to i
    // We want the sum from j to the left most tower
    // and we wan the sum from i to the left most tower - 1
    ll sumr = 0;
    ll suml = 0;
    for (int i = j - 1; i >= 0; i--) {
      suml += (j - point) * (positions[i + 1] - positions[i]);
      while (positions[j] - positions[point] < positions[point] - positions[i] && point > 0) {  // if point is closer to j than i, decrease once
        sumr += positions[j] - positions[point];
        suml += positions[point] - positions[i];
        point--;
      }
      cost_of_min_tower = cost[j];
      cost_of_min_tower += M[i];
      cost_of_min_tower -= (positions[j] - positions[i]) * (n - j - 1);

      cost_of_min_tower += sumr;
      cost_of_min_tower -= suml;

      if (min_tower > cost_of_min_tower) {
        min_tower = cost_of_min_tower;
      }
    };
    cost_of_teardown = cost[j];   // we do easier math (assume the only tower is the tower j)
    for (ll i = 0; i < n; i++) {  // current position in relation to all others
      cost_of_teardown += abs(positions[j] - positions[i]);
    }

    if (cost_of_teardown <= min_tower)
      M[j] = {cost_of_teardown};
    else
      M[j] = {min_tower};
    // cout << "COST: " << min_tower << " " << cost_of_teardown << "\n";
  }
  // for (auto& e : M) cout << e << '\n';

  ll result = *min_element(M.begin(), M.end());

  cout << result << '\n';

  return 0;
}