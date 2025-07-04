#include <bits/stdc++.h> // includes all; gcc only
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) begin(a), end(a)

using namespace std;
using ll = long long;

inline int moem_int()
{
    int x = 0;
    unsigned int c;
    while ((c = getchar_unlocked()) == ' ' || c == '\n')
        ;
    do
    {
        x = x * 10 + (c - '0');
    } while ((c = getchar_unlocked()) >= '0' && c <= '9');
    return x;
}
map<pair<int,int>,bool> queries;

bool custom(int a, int b){
    bool ans;
    if (a == b) return false;
    if (a<b){
        if(queries.contains({a,b})) return queries[{a,b}];
        cout << "? " << a << " " << b << endl;
        cin >> ans;
        queries[{a,b}] = ans;
        return ans;
    } else{
        if(queries.contains({b,a})) return queries[{b,a}];
        cout << "? " << b << ' ' << a << endl;
        cin >> ans;
        queries[{b,a}] =ans;
        return !ans;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.precision(10);

    // content
    int T;
    T = moem_int();
    vector<int> result(T);
    rep(a,T){
        result[a] = a+1; 
    }
    std::sort(result.begin(), result.end(), custom);

    cout << "! ";
    for (int res : result)
    {
        cout << res << " ";
    }
    cout << "\n";
}
