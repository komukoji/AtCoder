#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, K, sum = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int xi;
        cin >> xi;
        if (2 * xi < 2 * (K - xi))
        {
            sum += 2 * xi;
        }
        else
        {
            sum += 2 * (K - xi);
        }
    }
    cout << sum << endl;
}