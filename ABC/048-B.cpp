#include <bits/stdc++.h>
using namespace std;

long long a, b, x;

long long f(long long n)
{
    if (n == -1)
        return 0;
    else
        return (n / x) + 1;
}

int main()
{

    cin >> a >> b >> x;
    cout << f(b) - f(a - 1);
}