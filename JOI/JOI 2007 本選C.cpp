#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> point(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> point.at(i + 1);
    }

    vector<int> dp(N * N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp.at(N * i + j) = point.at(i) + point.at(j);
        }
    }

    sort(dp.begin(), dp.end());

    int maxpoint = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int sum = point.at(i) + point.at(j);
            if (sum > M)
                continue;
            else
            {
                sum += *prev(upper_bound(dp.begin(), dp.end(), M - sum));
                maxpoint = max(maxpoint, sum);
            }
        }
    }
    cout << maxpoint << endl;
}