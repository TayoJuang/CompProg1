#include <bits/stdc++.h>  // includes all; gcc only

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

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
  cout.precision(10);

  // content
  int row1, row2;
  int n;

  n = moem_int();
  // l, r, instr
  // priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
  // greater<>> minHeap;
  vector<tuple<int, int, int>> events;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> candidates;
  vector<int> results(n);
  for (int i = 0; i < n; i++) {
    row1 = moem_int();
    row2 = moem_int();
    events.emplace_back(row1, row2, i);
  }

  sort(all(events));
  int it = 0;
  rep(a, n) {
    while (it < n && get<0>(events[it]) <= a + 1) {
      auto top = events[it];
      candidates.emplace(get<1>(top), get<2>(top));
      it += 1;
    }
    cout << get<1>(candidates.top()) + 1 << " ";
    candidates.pop();
  }

  return 0;
}