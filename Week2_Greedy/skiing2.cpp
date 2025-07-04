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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    // content
    ll T;

    cin >> T;
    ll l = 0, r = T;
    bool ansL, ansR, ansNR, ansNL, ans;
    // ask for mid and mid+1, ask for 0 and mid
    //
    ll mid = (l + r) / 2;

    cout << "? " << 0 << " " << mid << endl;
    cin >> ans;
    if (ans)
    {
        cout << "? " << mid << " " << mid + 1 << endl;
        cin >> ansNR;
        cout << "? " << mid << " " << mid - 1 << endl;
        cin >> ansNL;
        if (ansNL == 0 && ansNR == 0)
        {
            cout << "! " << mid << endl;
            return 0;
        }
        if (ansNR)
        {
            l = mid, r = T;
        }
        else
        {
            l = 0, r = mid;
        }
        cout << "? 0 1" << endl;
        cin >> ansR;
        cout << "? 0 " << T - 1 << endl;
        cin >> ansL;
        if (ansL == 0 && ansR == 0)
        {
            cout << "! " << 0 << endl;
            return 0;
        }
    }
    else
    {
        cout << "? 0 1" << endl;
        cin >> ansR;
        cout << "? 0 " << T - 1 << endl;
        cin >> ansL;
        if (ansL == 0 && ansR == 0)
        {
            cout << "! " << 0 << endl;
            return 0;
        }
        if (ansR)
        {
            l = 0, r = mid;
        }
        else
        {
            l = mid, r = T;
        }
        cout << "? " << mid << " " << mid + 1 << endl;
        cin >> ansNR;
        cout << "? " << mid << " " << mid - 1 << endl;
        cin >> ansNL;
        if (ansNL == 0 && ansNR == 0)
        {
            cout << "! " << mid << endl;
            return 0;
        }
    }

    cout << l << " " << r << endl;
    while (r-l > 1)
    {

        ll mid = (l + r) / 2;
        ll left_neighbor = (mid - 1 + T) % T;
        ll right_neighbor = (mid + 1) % T;
        cout << "? " << mid << " " << left_neighbor << endl;
        cin >> ansL;

        cout << "? " << mid << " " << right_neighbor << endl;
        cin >> ansR;
        if (ansL == 0 && ansR == 0)
        {
            cout << "! " << mid << endl;
            return 0;
        }
        // if b > a 1 if b <= a 0
        if (ansL)
        { // left is bigger, so move left
            r = mid;
        }
        else
        {
            l = mid +1;
        }
        cout << l << " " << r << endl;
    }
}
