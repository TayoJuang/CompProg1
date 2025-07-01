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
    cout.precision(10);

    // content
    int t, row;

    t = moem_int();
    vector<vector<int>> tests(t);
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            row = moem_int();
            tests[i].emplace_back(row);
        }
    }
    bool possible = false;
    vector<int> p(5);
    for (int i = 0; i < t; i++)
    {
        p = tests[i];
        possible = false;
        std::ranges::sort(p);
        do
        {
            if ((((p[0] + p[1]) + p[2]) + p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) + p[2]) + p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) + p[2]) + p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) + p[2]) - p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) + p[2]) - p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) + p[2]) - p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) + p[2]) * p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) + p[2]) * p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) + p[2]) * p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) - p[2]) + p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) - p[2]) + p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) - p[2]) + p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) - p[2]) - p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) - p[2]) - p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) - p[2]) - p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) - p[2]) * p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) - p[2]) * p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) - p[2]) * p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) * p[2]) + p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) * p[2]) + p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) * p[2]) + p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) * p[2]) - p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) * p[2]) - p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) * p[2]) - p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) * p[2]) * p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) * p[2]) * p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] + p[1]) * p[2]) * p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) + p[2]) + p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) + p[2]) + p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) + p[2]) + p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) + p[2]) - p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) + p[2]) - p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) + p[2]) - p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) + p[2]) * p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) + p[2]) * p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) + p[2]) * p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) - p[2]) + p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) - p[2]) + p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) - p[2]) + p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) - p[2]) - p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) - p[2]) - p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) - p[2]) - p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) - p[2]) * p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) - p[2]) * p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) - p[2]) * p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) * p[2]) + p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) * p[2]) + p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) * p[2]) + p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) * p[2]) - p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) * p[2]) - p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) * p[2]) - p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) * p[2]) * p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) * p[2]) * p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] - p[1]) * p[2]) * p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) + p[2]) + p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) + p[2]) + p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) + p[2]) + p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) + p[2]) - p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) + p[2]) - p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) + p[2]) - p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) + p[2]) * p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) + p[2]) * p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) + p[2]) * p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) - p[2]) + p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) - p[2]) + p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) - p[2]) + p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) - p[2]) - p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) - p[2]) - p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) - p[2]) - p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) - p[2]) * p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) - p[2]) * p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) - p[2]) * p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) * p[2]) + p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) * p[2]) + p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) * p[2]) + p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) * p[2]) - p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) * p[2]) - p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) * p[2]) - p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) * p[2]) * p[3]) + p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) * p[2]) * p[3]) - p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
            if ((((p[0] * p[1]) * p[2]) * p[3]) * p[4] == 23)
            {
                possible = true;
                cout << "Possible\n";
                break;
            }
        } while (std::ranges::next_permutation(p).found);
            if (!possible) cout << "Impossible\n";
    }
    return 0;
}
