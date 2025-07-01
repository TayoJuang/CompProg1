#include <bits/stdc++.h> // includes all; gcc only
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

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
    //cout.precision(10);

    // content
    ll n;
    cin >> n;
    ll low = 0, high = n, mid = (high) / 2;
    // old_mid = n;
    int answer_adjacent1, answer_adjacent2, answer_opposing;
    bool bin = false, o = false;
    bool buffer;
   
    bool ansL, ansR, ansNL, ansNR;
    cout << "? " << 0 << " " << 0 + 1 << endl;
    ansR = moem_int();
    cout << "? " << 0 << " " << n -1 << endl;
    ansL = moem_int();

    cout << "? " << n-1 << " " << n-2 << endl;
    ansNL = moem_int();

    if(ansR == 0 && ansL == 0){
        cout << "! 0" << endl;
        return 0;
    }
    if (ansL == 1 && ansNL == 0)
    {
        cout << "! "<< n-1 << endl;
        return 0;
    }

    cout << "? " << mid % n << ' ' << (mid + 1) % n << endl;
    buffer = moem_int();
    answer_adjacent2 = buffer;
    
    cout << "? " << low % n << ' ' << (low + 1) % n << endl;
    buffer = moem_int();
    answer_adjacent1 = buffer;
    
    cout << "? " << low % n << ' ' << (mid + 1) % n << endl;
    buffer = moem_int();
    answer_opposing = buffer;
    
    if ((answer_adjacent1 && !answer_opposing) ||
        (!answer_adjacent2 && answer_opposing)) //so if low+1>low and low>mid+1 or mid+1>mid and mid+1>low
    { // interval 0 - n/2
        high = mid + 1;
        o = answer_opposing;
    }
    else
    { // interval n/2+1 - n
        low = mid; // to be safe include mid
        o = !answer_opposing; //invert just 2nd interval
    }
    if (answer_adjacent1 != answer_adjacent2)
    { // we can do binary, just go uphill
        bin = true;
    }
    if (!bin)
    { // ad1=ad2!=o
        rep(i, log2(n) + 1)
        {
            mid = (low + high) / 2;
            
            cout << "? " << mid % n << ' ' << (mid + 1) % n << endl;
            buffer = moem_int();
            answer_adjacent1 = buffer;
            
            if (answer_adjacent1 == o) // slopes are equal
            { // now we can do binary, go uphill
                bin = true;
                if (answer_adjacent1) low = mid;
                else high = mid + 1;
                break;
            }
            //potentially cooked
            cout << "? " << low % n << ' ' << (mid + 1) % n << endl;
            buffer = moem_int();
            answer_opposing = buffer; // getting new slope

            if (answer_opposing == o)
                high = mid+1; // peak and valley to the right
            else
                low = mid;
        }
    }
    if (bin)
    { // binary search
        while (high - low > 1)
        {
            // cout << low << " " << high << endl;
            mid = (low + high) / 2;
            // if (mid == old_mid) break;
            cout << "? " << mid % n << ' ' << (mid + 1) % n << endl;
            buffer = moem_int();
            answer_adjacent1 = buffer;
            cout << "? " << mid % n << ' ' << (mid  - 1 )% n << endl;
            buffer = moem_int();
            answer_adjacent2 = buffer;
            if(answer_adjacent1 == 0 && answer_adjacent2 == 0){
                cout << "! " << mid << '\n';
                return 0;
            }
            if (answer_adjacent1)
                low = mid;
            else
                high = mid + 1;
            // old_mid = mid;
        }
    }
    mid = (low + high) / 2;
    cout << "! " << mid << '\n';

    return 0;
}