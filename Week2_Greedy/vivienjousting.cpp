#include <bits/stdc++.h> // includes all; gcc only
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      begin(a),end(a)

using namespace std;
using ll = long long;

map<pair<uint,uint>,bool> queries;

bool compare (const uint a, const uint b) {
    bool answer;
    if (a <= b) {
        auto it = queries.find(w                                        (a,b));
        if (it != queries.end()) return it->second;
        cout << "? " << a << ' ' << b << endl;
        cin >> answer; // 0 if a wins, 1 if b wins
        queries.emplace(pair(a,b),answer);
    } else {
        auto it = queries.find(pair(b,a));
        if (it != queries.end()) return !it->second;
        cout << "? " << b << ' ' << a << endl;
        cin >> answer; // 0 if b wins, 1 if a wins
        queries.emplace(pair(b,a),answer);
        answer = !answer;
    }
    return answer;
}

uint divide(vector<uint>& order, const uint lo, const uint hi){
    uint uno = lo+1;
    uint dos = hi;
    uint temp;
    while(uno <= dos) {
        while (uno <= hi && compare(order[uno], order[lo])) uno++;
        while (dos > lo && compare(order[lo], order[dos])) dos--;
        if(uno < dos) { // swap elements
            temp = order[uno];
            order[uno] = order[dos];
            order[dos] = temp;
        }
    } //swap pivot
    temp = order[dos];
    order[dos] = order[lo];
    order[lo] = temp;
    return dos;
};

void qs(vector<uint>& order, const uint lo, const uint hi){
    if (lo < hi) {
        const uint pivot = divide(order,lo, hi);
        if (pivot > lo) qs(order,lo, pivot-1);
        if (pivot < hi) qs(order, pivot+1, hi);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    // content
    uint n;
    cin >> n;
    vector<uint> order(n);
    for(uint i = 0; i < n; ++i) {
        order[i] = i+1;
    }
    qs(order, 0, n-1);
    cout << "! ";
    for (auto& e : order) cout << e << ' ';

    return 0;
}