#include <bits/stdc++.h> // includes all; gcc only
// #include <iostream>
// #include <vector>
// #include <map>
// #include <unordered_map>
// #include <algorithm>
// #include <queue>
// #include <cmath>
// #include <set>

#define rep(a, b) for (lla = 0; a < (b); ++a)
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
    //cout.precision(10);

    // content
    int n, u, row;

    n = moem_int();
    u = moem_int();
    vector<int> problems(n);
    for (int i = 0; i < n; i++)
    {
        row = moem_int();
        problems[i] = row;
    }


    int num_problems = 0;
    int lower_bound = 0, upper_bound = n;
    ll avg = 0, sum =0;
    int result = 0;
     if (*max_element(problems.begin(), problems.end()) < u)
    {
        cout << 0;
        return 0;
    }

    while (lower_bound <= upper_bound){

        num_problems = (lower_bound + upper_bound +1) / 2;
        sum = 0;
        nth_element(problems.begin(), problems.begin() + (n - num_problems), problems.end());
        sum = accumulate(problems.begin()+ (n-num_problems), problems.end(), 0LL);
        if (num_problems == 0)
        {
            avg = 0;
        }
        else
        {
            avg = (sum) / num_problems;
        }
        //cout << avg << endl;
        if (avg >= u)
        {

            lower_bound = num_problems +1;
            result = max(result, num_problems);
        }
        else
        {
            upper_bound = num_problems - 1;
        }
    }
    cout << result;
}
