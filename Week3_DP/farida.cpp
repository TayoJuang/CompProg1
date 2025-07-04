#include <bits/stdc++.h> // includes all; gcc only

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) begin(a), end(a)

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    // content
    int N, row;

    cin >> N;
    vector<ll> coins(N+1);

    coins[0] = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> row;
        coins[i+1] = row;
    }
    //(0) 5 4 9 2
    for(int i = 0; i<N+2;i++){
        coins[i+1] = max(coins[i], coins[i-1] + coins[i+1]);
    }
    cout << coins[N+1] << "\n";
}
