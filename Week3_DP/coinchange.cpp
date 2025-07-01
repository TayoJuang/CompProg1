#include <bits/stdc++.h>  // includes all; gcc only

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) begin(a), end(a)

using namespace std;
using ll = long long;

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
  //cout.precision(10);
  // content
  int t, X, C;
  int row;
  t = moem_int();
  for (int i = 0; i < t; i++) {
    X = moem_int();
    C = moem_int();
    int coins[C];
    for (int j = 0; j < C; j++) {
      row = moem_int(); 
      coins[j] = row;
    }

    vector<int> values(X + 3000, 0);
    queue<int> a_queue;
    for (auto coin : coins){
      values[coin] = 1;
      a_queue.push(coin);
    }

    while (!a_queue.empty() && values[X] == 0){
      int front = a_queue.front();
      a_queue.pop();
      for (int coin : coins){
        int next = front + coin;
        if(next >= (int)values.size()){
          values.resize(2*values.size());
        }
        if (values[next] == 0) {
          values[next] = values[front] + 1;
          a_queue.push(next);
        }
        next = front - coin;

        if (next >= 0 && values[next] == 0) {
          values[next] = values[front] + 1;
          a_queue.push(next);
        }
      }
    }
    cout << values[X] << "\n";
  }
}
