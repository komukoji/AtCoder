#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, D;
    cin >> N >> D;
    int I = 0, J = 0, K = 0;
    while (D % 2 == 0)
    {
        D /= 2;
        I++;
    }
    while (D % 3 == 0)
    {
        D /= 3;
        J++;
    }
    while (D % 5 == 0)
    {
        D /= 5;
        K++;
    }
    if (D != 1)
    {
        cout << 0 << endl;
        return 0;
    }
    // n回サイコロを振って、素因数分解したら2**i * 3**j * 5**kになる確率
    vector<vector<vector<vector<double>>>> dp(N + 1, vector<vector<vector<double>>>(I + 1, vector<vector<double>>(J + 1, vector<double>(K + 1, 0))));
    dp.at(0).at(0).at(0).at(0) = 1.0000000;
    for (int n = 0; n < N; n++)
    {
        for (int i = 0; i <= I; i++)
        {
            for (int j = 0; j <= J; j++)
            {
                for (int k = 0; k <= K; k++)
                {
                    double cur = dp.at(n).at(i).at(j).at(k);
                    // 1が出たら
                    dp.at(n + 1).at(i).at(j).at(k) += cur / 6.0;

                    // 2が出たら
                    dp.at(n + 1).at(min(i+1,I)).at(j).at(k) += cur / 6.0;

                    // 3が出たら
                    dp.at(n + 1).at(i).at(min(j+1,J)).at(k) += cur / 6.0;

                    // 4が出たら
                    dp.at(n + 1).at(min(i + 2, I)).at(j).at(k) += cur / 6.0;

                    // 5が出たら
                    dp.at(n + 1).at(i).at(j).at(min(k+1,K)) += cur / 6.0;

                    // 6が出たら
                    dp.at(n + 1).at(min(i + 1, I)).at(min(j+1,J)).at(k) += cur / 6.0;
                }
            }
        }
    }

    cout << setprecision(20) << dp.at(N).at(I).at(J).at(K) << endl;
}
