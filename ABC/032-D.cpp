#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
//TODO 半分全列挙らしいのであとで！

int main()
{
    int N, W;
    cin >> N >> W;
    vector<int> v(N), w(N);
    int vmax = 0, wmax = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> v.at(i) >> w.at(i);
        vmax = max(vmax, v.at(i));
        wmax = max(wmax, w.at(i));
    }

    if (N <= 30)
    {
    }
    else if (vmax <= 1000)
    {
        // i番目の品物、価値jの重さの最小値
        vector<vector<long long>> dp(N + 1, vector<long long>(N * vmax + 1, INF));
        dp.at(0).at(0) = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= N * vmax; j++)
            {
                if (j - v.at(i) < 0)
                {
                    dp.at(i + 1).at(j) = dp.at(i).at(j);
                }
                else
                {
                    dp.at(i + 1).at(j) = min(dp.at(i).at(j), dp.at(i).at(j - v.at(i)) + w.at(i));
                }
            }
        }
        long long res = 0;
        for (int j = 0; j <= N * vmax; j++)
        {
            if (dp.at(N).at(j) <= W && j > res)
            {
                res = j;
            }
        }
        cout << res << endl;
    }
    else if(wmax <= 1000){
        //i番目の品物,重さ容量jの最大価値
        vector<vector<int>> dp(N + 1, vector<int>(N * wmax + 1, 0));
        for (int i = 0; i < N;i++){
            for (int j = 0; j <= N * wmax;j++){
                if(j - w.at(i) <0){
                    dp.at(i + 1).at(j) = dp.at(i).at(j);
                }
                else{
                    dp.at(i + 1).at(j) = max(dp.at(i).at(j), dp.at(i).at(j - w.at(i)) + v.at(i));
                }
            }
        }
        cout << dp.at(N).at(min(W, N * wmax)) << endl;
    }
}
