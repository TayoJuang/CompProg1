// #include <bits/stdc++.h> // includes all; gcc only
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
    while ((c = getchar_unlocked()) == ' ' || c == '\n');
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
    //cout.precision(10);

    // content
    ll row;
    int m, n;
    moem_int;

    cin >> n;
    cin >> m;
    // 0. pos 1. inst number 2. l is 0 and r is 1
    priority_queue<tuple<ll, int, bool>, vector<tuple<ll, int, bool>>, greater<>> minHeap;
    vector<ll> results(n);
    vector<int> colors(m);                         // instruction (m) to color
    priority_queue<tuple<int, int, ll>> colorHeap; // instr, color, pos
    vector<bool> usedInstr(m, 1);                  // all instrs are active
    for (int i = 0; i < m; i++)
    { 
        cin >> row;
        minHeap.emplace(row, i, 0);
        cin >> row;
        minHeap.emplace(row, i, 1);
        cin >> row;
        colors[i] = row;
    }
    auto meh = minHeap.top();
    ll alt = get<0>(meh);
    while (!minHeap.empty())
    {
        auto top = minHeap.top();
        if (get<2>(top) == 0) // if left
        {
            if (!colorHeap.empty())
            {
                auto color = colorHeap.top();
                while (!usedInstr[get<0>(color)]) // if not active
                {
                    colorHeap.pop();
                    if (colorHeap.empty())
                        break;
                    color = colorHeap.top();
                }
                if (!colorHeap.empty())
                {
                    results[get<1>(color)] += get<0>(top) - alt;
                }
            }
            colorHeap.push({get<1>(top), colors[get<1>(top)], get<0>(top)});
        }
        else if (get<2>(top) == 1) // if right
        {
            if (!colorHeap.empty())
            {
                auto color = colorHeap.top();
                while (!usedInstr[get<0>(color)]) // if not active
                {
                    colorHeap.pop();
                    if (colorHeap.empty())
                        break;
                    color = colorHeap.top();
                }
                if (!colorHeap.empty())
                {
                    results[get<1>(color)] += get<0>(top) - alt;
                }
                usedInstr[get<1>(top)] = 0;
            }
        }
        alt = get<0>(top);
        minHeap.pop();
    }
    for (auto color : results)
    {
        cout << color << "\n";
    }
}
