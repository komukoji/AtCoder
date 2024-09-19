#include <bits/stdc++.h>
using namespace std;
const vector<int> coin = {500, 100, 50, 10, 5, 1};

int main(){
    int N;
    cin >> N;
    int change = 1000 - N;
    int ans = 0;
    for (size_t i = 0; i < 6; i++)
    {
        int t = change / coin.at(i);
        change -= t * coin.at(i);
        ans += t;
    }
    cout << ans << endl;
}