#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;

int main()
{
    int N;
    long long K;
    cin >> N >> K;
    // i日目のゲーム数、0-index
    vector<int> a(N);
    for (int &p : a)
    {
        cin >> p;
    }

    // i日目までの累計ゲーム数,1-index
    vector<long long> num_games(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        num_games.at(i) = num_games.at(i - 1) + a.at(i - 1);
    }
    if (num_games.at(N) == K)//全勝したら1回だけ、Kが全試合数未満ならできるだけ早いうちに負けとけばあと絶対勝てる
    {
        cout << 1 << endl;
        return 0;
    }

    /*
    普通の発想ならdpをi日目までにj回勝った時の機嫌のいい日最大にしたいが、勝利数Kが果てし無くでかくなりうるので組めない
    ↓
    勝利数が余っても、最終日から勝利数重ねれば勝率が下がることはない
    dpを、i日目までにj回勝率が上がった日数(機嫌が良かった日数)、中身を最小勝利数に設計する
    dp[N][j]がK以下になる最大のjが答え
    */
    vector<vector<long long>> dp(N + 1, vector<long long>(N + 1, INF));
    for (int i = 0; i <= N; i++)
    { // 何日目でも0日気分良くなるには0回勝利でいい
        dp.at(i).at(0) = 0;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            /*遷移は前日までにj日機嫌良くてi日目は0勝 or 前日までにj-1日機嫌良くてi日目に必要最低回数勝利
            i-1日目までにx回ゲームしててy回勝利し、i日目にai回ゲームしてbi回勝った時、勝率が上がるのは
            y/x < (y+bi)/(x+ai)となる時機嫌がいい
            これを解くと
            bi > y*ai/x
            */
            if (i == 0)
            { // 初日は前日までの勝率がない(0)→気分がいい日になるには1回勝利でOK
                dp.at(i + 1).at(j + 1) = 1;
                continue;
            }
            dp.at(i + 1).at(j + 1) = min(dp.at(i).at(j) + (dp.at(i).at(j) * a.at(i) + num_games.at(i)) / num_games.at(i), dp.at(i).at(j + 1));
        }
    }

    int res = 0;
    for (int j = 0; j <= N; j++)
    {
        if (dp.at(N).at(j) <= K)
        {
            res = j;
        }
    }
    cout << res << endl;
}
