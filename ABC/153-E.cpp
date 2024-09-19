#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;

int main()
{
    int H, N;
    cin >> H >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i) >> B.at(i);
    }
    vector<vector<int>> dp(N + 1, vector<int>(H + 1, 0));
    dp.at(0).at(0) = 0;
    for (int i = 1; i <= H; i++)
    {
        dp.at(0).at(i) = INT_MAX;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= H; j++)
        {
            if (j - A.at(i) < 0)
            {
                dp.at(i + 1).at(j) = min(dp.at(i).at(j), dp.at(i + 1).at(0) + B.at(i));
            }
            else
            {
                dp.at(i + 1).at(j) = min(dp.at(i).at(j), dp.at(i + 1).at(j - A.at(i)) + B.at(i));
            }
        }
    }
    cout << dp.at(N).at(H) << endl;
}
