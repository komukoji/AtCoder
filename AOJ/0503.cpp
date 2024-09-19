#include <bits/stdc++.h>
using namespace std;

vector<int> ternary(15, 1);
int n, m;
int goalA, goalC;

int bfs(int start)
{
    queue<pair<int, int>> que;
    que.push(make_pair(start, 0));
    int ans = -1;
    set<int> checked;
    while (que.size())
    {
        int state, step;
        tie(state, step) = que.front();
        checked.insert(state);
        que.pop();

        // ステップがm回超えたら不可能
        if (step > m)
        {
            break;
        }

        // ゴールで終了
        if (state == goalA || state == goalC)
        {
            ans = step;
            break;
        }

        // A,B,Cトレーにある最大のカップ
        int maxA = 0, maxB = 0, maxC = 0;
        for (size_t i = 0; i < n; i++)
        {
            if (state % (ternary.at(i) * 3) / ternary.at(i) == 0)
            {
                maxA = i + 1;
            }
            if (state % (ternary.at(i) * 3) / ternary.at(i) == 1)
            {
                maxB = i + 1;
            }
            if (state % (ternary.at(i) * 3) / ternary.at(i) == 2)
            {
                maxC = i + 1;
            }
        }

        // 左→真ん中
        if (maxA > maxB && !checked.count(state + ternary.at(maxA - 1)))
        {
            que.push(make_pair(state + ternary.at(maxA - 1), step + 1));
        }
        // 真ん中→左
        if (maxB > maxA && !checked.count(state - ternary.at(maxB - 1)))
        {
            que.push(make_pair(state - ternary.at(maxB - 1), step + 1));
        }
        // 真ん中→右
        if (maxB > maxC && !checked.count(state + ternary.at(maxB - 1)))
        {
            que.push(make_pair(state + ternary.at(maxB - 1), step + 1));
        }
        // 右→真ん中
        if (maxC > maxB && !checked.count(state - ternary.at(maxC - 1)))
        {
            que.push(make_pair(state - ternary.at(maxC - 1), step + 1));
        }
    }
    return ans;
}

int main()
{
    // 3進数の準備
    for (size_t i = 1; i < 15; i++)
    {
        ternary.at(i) = ternary.at(i - 1) * 3;
    }

    while (cin >> n >> m)
    {
        // 終了入力
        if (n == 0 && m == 0)
            break;

        // ゴール
        goalA = goalC = 0;
        for (size_t i = 0; i < n; i++)
        {
            goalC += 2 * ternary.at(i);
        }

        // スタート
        int start = 0;
        for (size_t i = 0; i < 3; i++)
        {
            int tray;
            cin >> tray;
            for (size_t j = 0; j < tray; j++)
            {
                int cupsize;
                cin >> cupsize;
                start += ternary.at(cupsize - 1) * i;
            }
        }

        cout << bfs(start) << endl;
    }
}