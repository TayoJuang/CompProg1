#include <bits/stdc++.h>  // includes all; gcc only

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) begin(a), end(a)

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);

  // content
  ll n, m;

  cin >> n >> m;
  vector<pair<ll, ll>> team(n);
  vector<pair<ll, ll>> problems(m);
  ll row;
  for (ll i = 0; i < n; i++) {
    cin >> row;
    team[i] = {row, i};
  }
  for (ll i = 0; i < m; i++) {
    cin >> row;
    problems[i] = {row, i};
  }

  ranges::sort(team, ranges::greater());
  ranges::sort(problems, ranges::greater());
  vector<pair<ll, ll>> result;
  ll k = 0;
  for (ll i = 0; i < n; i++) {
    if(k >= m){break;}
    while (get<0>(team[i]) < get<0>(problems[k]) && k<m){
        k++;
    }
    if (k >= m) {
      break;
    }
    if (get<0>(team[i]) >= get<0>(problems[k])) {
      result.emplace_back(get<1>(team[i]), get<1>(problems[k]));
      k++;
    }
  }
  cout << result.size() << "\n";
  for(auto in : result){
    cout << get<0>(in)+1 << " " << get<1>(in)+1 << "\n"; 
  }
}
