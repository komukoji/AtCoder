#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

int main()
{
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }
        int yaku = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                yaku++;
            }
        }
        if (yaku == 8)
        {
            ans++;
        }
    }
    cout << ans << endl;
}
