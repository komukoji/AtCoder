#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long inf = 1000000007;
    int D;
    string N;
    cin >> D;
    cin >> N;
    int L = N.size();
    // i桁目、未満確定フラグ、各桁の和
    vector<vector<vector<long long>>> dp(L + 1, vector<vector<long long>>(2, vector<long long>(D, 0)));
    dp.at(0).at(0).at(0) = 1;
    for (int i = 0; i < L; i++)
    {
        for (int smaller = 0; smaller < 2; smaller++)
        {
            for (int j = 0; j < D; j++)
            {
                for (int x = 0; x <= (smaller ? 9 : N.at(i) - '0'); x++)
                {
                    dp.at(i + 1).at(smaller || x < N.at(i) - '0').at(j) += dp.at(i).at(smaller).at(j - x >= 0 ? (j - x) % D : ((j - x) % D + D) % D);
                    dp.at(i + 1).at(smaller || x < N.at(i) - '0').at(j) %= inf;
                }
            }
        }
    }
    cout << ((dp.at(L).at(0).at(0) + dp.at(L).at(1).at(0)) - (dp.at(0).at(0).at(0)+dp.at(0).at(1).at(0))) % inf << endl;
}
