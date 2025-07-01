#include <bits/stdc++.h>  // includes all; gcc only

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) begin(a), end(a)

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);

  // content
  int n, row;

  cin >> n;

  vector<int> dp_inc(n, 1);
  vector<int> dp_dec(n, 1);
  vector<int> difficulties(n);

  for (int i = 0; i < n; i++) {
    cin >> row;
    difficulties[i] = row;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (difficulties[i] > difficulties[j]) {
        dp_inc[i] = max(dp_inc[i], dp_inc[j] + 1);
      }
    }
  }
  for (int i = n - 2; i > -1; i--) {
    for (int j = i + 1; j < n; j++) {
      if (difficulties[i] > difficulties[j]) {
        dp_dec[i] = max(dp_dec[i], dp_dec[j] + 1);
      }
    }
  }

  vector<int> dp_result(n);
  for (int i = 0; i < n; i++) {
    dp_result[i] = dp_dec[i] + dp_inc[i] - 1;
  }
  int max_ele = *max_element(dp_result.begin(), dp_result.end());

  cout << max_ele << "\n";
}
