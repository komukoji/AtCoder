#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
    cin >> N;
    M = N;
    int sum = 0;
    while (N != 0)
    {
        sum += N % 10;
        N /= 10;
    }
    if (M % sum == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
