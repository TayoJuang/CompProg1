#include <bits/stdc++.h> // includes all; gcc only

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
    int n,M;

    cin >> n >> M;
    vector<int> items(3,0);
    int item;
    for(int i = 0; i<n;i++){
        cin >> item;
        items[item-1]++; 
    }
    int result = 0;
    int x;
    bool usedThree = false;
    x = min((M/3),items[2]);
    if(x >= 1){
        usedThree = true;
    }
    result += 3*x;
    M -= 3*x;
    
    x = min((M/2),items[1]);
    items[1] -= x;
    result += 2 * x;
    M -= 2 * x;

    x = min((M), items[0]);
    items[0] -= x;
    result += x;
    M -= x;

    if(M==1 && 2*items[1]+items[0] >=4 && usedThree == true){
        result+=1;
    }
    cout << result << "\n";
}
