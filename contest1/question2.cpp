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
  int p;
  string a;
  string b;

  cin >> p;
  for (int i = 0; i < p; i++) {
    cin >> a >> b;
    ranges::sort(a);
    ranges::sort(b);
    if(a == b){
        cout << 1 << "\n";
    } else{
        cout << 0 << "\n";
    }
  }
}
