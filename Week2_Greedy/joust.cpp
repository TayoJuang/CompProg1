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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // cout.precision(10);

    // content
    int T, row;
    bool ans;
    T = moem_int();
    vector<int> result;
    result.reserve(T);
    result.emplace_back(1);
    int l,r,mid;
    for (int b = 2; b <= T; b++)
    {
        l = 0, r = result.size();
        while (l < r)
        {
            mid = (l + r) / 2;
            cout << "? " << b << " " << result[mid] << "\n";
            cout.flush();
            ans = moem_int();
            if (ans)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        result.insert(result.begin()+l,b);
    }

    cout << "! ";
    for (int res : result)
    {
        cout << res << " ";
    }
    cout << "\n";
}
