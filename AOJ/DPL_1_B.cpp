#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, W;
    vector<vector<int>> dp;
    cin >> N >> W;
    dp.assign(N + 1, vector<int>(W + 1, 0));
    vector<int> w(N), v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v.at(i) >> w.at(i);
    }
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = 0; j <= W; j++)
        {
            if (j < w.at(i))
            {
                dp.at(i).at(j) = dp.at(i + 1).at(j);
            }
            else
            {
                dp.at(i).at(j) = max(dp.at(i + 1).at(j), dp.at(i + 1).at(j - w.at(i)) + v.at(i));
            }
        }
    }
    cout << dp.at(0).at(W) << endl;
}
