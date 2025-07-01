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
  int n,k;
  string a;
  cin >> n >> k >> a;
  vector<pair<char, int>> str(n);
    for(int i = 0; i< a.size();i++){
        str[i]= {a[i], i};
    }
    ranges::sort(str);
    vector<int> strdelete(k);

    for(int i = 0; i< k; i++){
      strdelete[i] = get<1>(str[i]); 
    }
    ranges::sort(strdelete, ranges::greater());
    for (int i = 0; i < k; i++) {
      a.erase(strdelete[i],1);
    }
    cout << a << "\n";
}
