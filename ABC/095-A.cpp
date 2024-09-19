#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int ans = 700;
    for (char p : s)
    {
        if (p == 'o')
            ans += 100;
    }
    cout << ans << endl;
}