
// #include <bits/stdc++.h> // includes all; gcc only
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) begin(a), end(a)

using namespace std;
using ll = int;

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
    int n, a, b, c;

    n = moem_int();
    a = moem_int();
    b = moem_int();
    c = moem_int();

    ll noCard = n * 100;
    ll twentyFiveCard = n * 75 + a;
    ll fiftyCard = n * 50 + b;
    ll hundredCard = c;

    unordered_map<ll, std::string> cardMap;
    cardMap[noCard] = "no Bahncard";
    cardMap[twentyFiveCard] = "Bahncard 25";
    cardMap[fiftyCard] = "Bahncard 50";
    cardMap[hundredCard] = "Bahncard 100";

    ll minCost = min({noCard, twentyFiveCard, fiftyCard, hundredCard});
    cout << cardMap[minCost] << "\n";

    return 0;
}
