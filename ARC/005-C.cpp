#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<string> c;
vector<vector<int>> d;
vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

bool bfs()
{
    queue<pair<int, int>> que;
    d.assign(H, vector<int>(W, -1));
    int sx, sy, gx, gy;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (c.at(i).at(j) == 's')
            {
                sx = i;
                sy = j;
            }
            if (c.at(i).at(j) == 'g')
            {
                gx = i;
                gy = j;
            }
        }
    }

    que.push(make_pair(sx, sy));
    d.at(sx).at(sy) = 0;
    while (que.size())
    {
        pair<int, int> p = que.front();
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = p.first + dx.at(i), ny = p.second + dy.at(i);
            // 範囲外なら飛ばす
            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;
            // 到達済かつ、次が壁で現在の壁破壊回数+1以下or壁じゃなくて現在の壁破壊回数以下
            if (d.at(nx).at(ny) != -1 && ((c.at(nx).at(ny) == '#' && d.at(nx).at(ny) <= d.at(p.first).at(p.second) + 1) || c.at(nx).at(ny) != '#' && d.at(nx).at(ny) <= d.at(p.first).at(p.second)))
                continue;
            que.push(make_pair(nx, ny));
            if (c.at(nx).at(ny) == '#')
                d.at(nx).at(ny) = d.at(p.first).at(p.second) + 1;
            else
                d.at(nx).at(ny) = d.at(p.first).at(p.second);
        }
    }

    return d.at(gx).at(gy) <= 2;
}

int main()
{
    cin >> H >> W;
    c.resize(H);
    for (string &p : c)
        cin >> p;

    if (bfs())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
