#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(N), c(N), w(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a.at(i) >> b.at(i) >> c.at(i) >> w.at(i);
    }
    vector<int> x(M), y(M), z(M);
    for (int i = 0; i < M; i++)
    {
        cin >> x.at(i) >> y.at(i) >> z.at(i);
    }
    // i,j,kの能力を持つときの最大給料
    vector<vector<vector<int>>> dp(101, vector<vector<int>>(101, vector<int>(101, 0)));
    for (int i = 0; i < N; i++)
    {
        dp.at(a.at(i)).at(b.at(i)).at(c.at(i)) = max(dp.at(a.at(i)).at(b.at(i)).at(c.at(i)), w.at(i));
    }

    for (int ai = -1; ai < 100; ai++)
    {
        for (int bi = -1; bi < 100; bi++)
        {
            for (int ci = -1; ci < 100; ci++)
            {
                dp.at(ai + 1).at(bi + 1).at(ci + 1) = max(dp.at(ai + 1).at(bi + 1).at(ci + 1), max(dp.at(max(ai, 0)).at(bi + 1).at(ci + 1), max(dp.at(ai + 1).at(max(bi, 0)).at(ci + 1), dp.at(ai + 1).at(bi + 1).at(max(ci, 0)))));
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        cout << dp.at(x.at(i)).at(y.at(i)).at(z.at(i)) << endl;
    }
}
