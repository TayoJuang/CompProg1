#include <bits/stdc++.h> // includes all; gcc only

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

inline string moem_string()
{
    string str;
    char c;
    while ((c = getchar_unlocked()) == ' ' || c == '\n')
        ;
    str.push_back(c);
     while ((c = getchar_unlocked()) != ' ' && c != '\n' && c != EOF){
        str.push_back(c);
     }
    return str;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    // content
    int T, n;
    string row;

    T = moem_int();
    for (int a = 0; a < T; a++)
    {
        n = moem_int();
        row = moem_string();
        vector<bool> bit_row(n);
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            if (row[i] == 'W')
                bit_row[i] = false;
            else
                bit_row[i] = true;
        }
        // all 0
        vector<bool> copy_bit = bit_row;
        rep(i, n - 1)
        {
            if (copy_bit[i])
            {
                copy_bit[i] = !copy_bit[i];
                copy_bit[i + 1] = !copy_bit[i + 1];
                result.emplace_back(i +1);
            }
        }
        bool works = true;
        for (bool it : copy_bit)
        {
            if (it)
            {
                works = false;
                break;
            }
        }
        if (works)
        {
            cout << "YES\n";
            cout << result.size() << "\n";
            for (int it : result)
            {
                cout << it << " ";
            }
            cout << "\n";
            continue;
        }
        result.clear();
        //all 1
        rep(i, n-1){
            if(!bit_row[i]){
                bit_row[i] = !bit_row[i];
                bit_row[i + 1] = !bit_row[i + 1];
                result.emplace_back(i + 1);
            }
        }
        works = true;
        for (bool it : bit_row)
        {
            if (!it)
            {
                works = false;
                break;
            }
        }
        if (works)
        {
            cout << "YES\n";
            cout << result.size() << "\n";
            for (int it : result)
            {
                cout << it << " ";
            }
            cout << "\n";
            continue;
        }
        else{
            cout << "NO\n";
        }
    }
}
