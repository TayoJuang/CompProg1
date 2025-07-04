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
  int t;

  cin >> t;
  ll n,w,h;
  for (int i = 0; i < t; i++) {
    cin >> n >> w >> h;

    ll low = 1; 
    ll high = n*max(w,h) + 1;
    ll s;
    while(low < high){
        s = (low + high)/2;
        ll place = (s/w) * (s/h);
        if (place >= n){
            high = s;
        } else{
            low = s + 1;
        }
    }
    s = low;
    cout << s << "\n";
  }

}
