#include <bits/stdc++.h>
using namespace std;

// 中途半端に解く問題は1or0→i番目の問題を全部解くかとかないかで場合分け探索し、末端まできたら残りの問題で最大得点を解く
void dfs(int &ans, int i, int sum, int count, vector<int> rest, int &D, int &G, vector<pair<int, int>> &score)
{
    // i番目の問題を解くかとかないかで深さ優先探索
    if (i == D)
    { // 最後まで調べ終わったら残っている問題のうち最大得点の問題を解く
        if (sum < G)
        {
            int use = -1;
            for (int i = 0; i < rest.size(); i++)
            {
                if (rest.at(i) != -1)
                    use = i;
            }
            if (use == -1)
                return;
            int n = min(score.at(use).first, (G - sum + (use + 1) * 100 - 1) / ((use + 1) * 100));
            count += n;
            sum += n * (use + 1) * 100;
        }
        if (sum >= G)
        { // 点数が目標点を超えたら小さい方に答えをすげ替える
            ans = min(ans, count);
        }
        return;
    }
    else
    {
        // i番目の問題を解くかとかないかで分岐する再帰ステップ
        // 解かない場合
        dfs(ans, i + 1, sum, count, rest, D, G, score);
        // 解く場合
        rest.at(i) = -1;
        dfs(ans, i + 1, sum + score.at(i).first * (i + 1) * 100 + score.at(i).second, count + score.at(i).first, rest, D, G, score);
    }
}

int main()
{
    int D, G;
    cin >> D >> G;
    vector<pair<int, int>> score(D);
    int sumMAX = 0;
    for (auto &p : score)
    {
        cin >> p.first >> p.second;
        sumMAX += p.first;
    }
    vector<int> rest(D, 1);
    dfs(sumMAX, 0, 0, 0, rest, D, G, score);
    cout << sumMAX << endl;
}