#include <bits/stdc++.h>
using namespace std;

int main()
{
    int W, N, K;
    cin >> W >> N >> K;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i) >> B.at(i);
    }
    // i番目までの写真の中で、残り幅w,残り枚数kの中の価値の最大値
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(W + 1, vector<int>(K + 1, 0)));
    for (int i = 0; i < N; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            for (int k = 0; k <= K; k++)
            {
                if (k == 0)
                { // もう増やせないので次へ
                    dp.at(i + 1).at(w).at(k) = dp.at(i).at(w).at(k);
                    continue;
                }
                if (w - A.at(i) < 0)
                { // 幅が足りないので次へ
                    dp.at(i + 1).at(w).at(k) = dp.at(i).at(w).at(k);
                }
                else
                {
                    dp.at(i + 1).at(w).at(k) = max(dp.at(i).at(w).at(k), dp.at(i).at(w - A.at(i)).at(k - 1) + B.at(i));

                }
            }
        }
    }

    cout << dp.at(N).at(W).at(K) << endl;
}
