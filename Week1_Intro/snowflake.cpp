#include <bits/stdc++.h> // includes all; gcc only
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.precision(10);

    int T;
    cin >> T;
    short int n;
    cout << n <<endl;
    for (int i = 0; i < T; i++)
    {
        cin >> n;

        unordered_map<int, int> candidates;
        candidates.reserve(n);
        int startPos = 0;
        int maxLen = 0;

        for (int j = 0; j < n; j++)
        {
            int currVal;
            cin >> currVal;

            auto it = candidates.find(currVal);
            if (it != candidates.end() && it->second >= startPos)
            {
                maxLen = max(maxLen, j - startPos);
                startPos = it->second + 1;
            }
            candidates[currVal] = j;
        }

        maxLen = max(maxLen, n - startPos);
        cout << maxLen << "\n";
    }

    return 0;
}