#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long ans = 1;
    for (int i = 0; i < N; i++)
    {
        ans *= i + 1;
        ans %= (long long)pow(10, 9) + 7;
    }
    cout << ans << endl;
}