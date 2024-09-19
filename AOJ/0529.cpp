#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    while (cin >> N >> M)
    {
        if(N==0&&M==0)
            break;
        vector<int> point(N + 1, 0);
        for (int i = 0; i < N; i++)
        {
            cin >> point.at(i + 1);
        }

        vector<int> dp((N+1) * (N+1));
        for (int i = 0; i < N+1; i++)
        {
            for (int j = 0; j < N+1; j++)
            {
                dp.at((N+1) * i + j) = point.at(i) + point.at(j);
            }
        }
        sort(dp.begin(), dp.end());

        int maxpoint = 0;
        for (int i = 0; i < N+1; i++)
        {
            for (int j = 0; j < N+1; j++)
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
}