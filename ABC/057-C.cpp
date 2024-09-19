#include <bits/stdc++.h>
using namespace std;

int F(int long A, int long B)
{
    int i = 0;
    while (A > 0)
    {
        i++;
        A /= 10;
    }
    int j = 0;
    while (B > 0)
    {
        j++;
        B /= 10;
    }
    return max(i, j);
}

int main()
{
    int long N;
    cin >> N;

    int ans = 11;
    for (int i = 1; i <= sqrt(N); i++)
    {
        if (N % i == 0)
        {
            ans = min(ans, F(i, N / i));
        }
    }
    cout << ans << endl;
}