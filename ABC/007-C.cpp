#include <bits/stdc++.h>
using namespace std;

int R, C, sx, sy, gx, gy;
vector<string> c;
vector<vector<int>> d;

vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

int bfs()
{
    queue<pair<int, int>> que;
    d.assign(R, vector<int>(C, -1));
    que.push(make_pair(sx, sy));
    d.at(sx).at(sy) = 0;

    while (que.size())
    {
        pair<int, int> p = que.front();
        que.pop();
        if (p.first == gx && p.second == gy)
            break;

        for (int i = 0; i < 4; i++)
        {
            int nx = p.first + dx.at(i), ny = p.second + dy.at(i);
            if (nx < 0 || nx >= R || ny < 0 || ny >= C || c.at(nx).at(ny) == '#' || d.at(nx).at(ny) != -1)
                continue;

            que.push(make_pair(nx, ny));
            d.at(nx).at(ny) = d.at(p.first).at(p.second) + 1;
        }
    }
    return d.at(gx).at(gy);
}

int main()
{
    cin >> R >> C;
    c.resize(R);
    cin >> sx >> sy >> gx >> gy;
    sy--;
    sx--;
    gy--;
    gx--;
    for (string &p : c)
        cin >> p;

    cout << bfs() << endl;
}