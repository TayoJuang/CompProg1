// #include <bits/stdc++.h> // includes all; gcc only
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

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
    string s,t;
    cin >> s >> t;

    bool r = count(t.begin(),t.end(),'r') % 2;
    bool h = count(t.begin(), t.end(), 'h') % 2;
    bool v = count(t.begin(), t.end(), 'v') % 2;

    if (r && h)
    {
        r = !r;
        h = !h;
        v = !v;
    }
    else if (r && v)
    {
        r = !r;
        v = !v;
        h = !h;
    }
    else if (h && v)
    {
        h = !h;
        v = !v;
        r = !r;
    }
    //cout << r << h << v << endl;
    if (h || r){
        reverse(s.begin(), s.end());
    }
    for (char &c : s){
        if (r){
            //180
            if (c == 'b') c = 'q';
            else if (c == 'q') c = 'b';
            else if (c == 'p') c = 'd';
            else if (c == 'd') c = 'p';
        }
        else if (h){
            //hor
            if (c == 'b') c = 'd';
            else if (c == 'd') c = 'b';
            else if (c == 'p') c = 'q';
            else if (c == 'q') c = 'p';
        }
        else if (v){
            //ver
            if (c == 'b') c = 'p';
            else if (c == 'p') c ='b';
            else if (c == 'q') c = 'd';
            else if (c == 'd') c = 'q';
        }
    }
    cout << s << '\n';
}

