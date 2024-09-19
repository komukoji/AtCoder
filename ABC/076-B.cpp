#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;
    int a = 1;
    for (int i = 0; i < N; i++)
    {
        if (a < K)
        {
            a *= 2;
        }
        else
        {
            a += K;
        }
    }
    cout << a << endl;
}