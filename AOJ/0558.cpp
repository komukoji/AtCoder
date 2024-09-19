#include <bits/stdc++.h>
using namespace std;

int H, W, N;
vector<string> c;
vector<vector<int>> d;
vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

int bfs(char s, char g)
{
    d.assign(H, vector<int>(W, -1));
    queue<pair<int, int>> que;
    int sx, sy, gx, gy;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (c.at(i).at(j) == s)
            {
                sx = i;
                sy = j;
            }
            if (c.at(i).at(j) == g)
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
        if (p.first == gx && p.second == gy)
            break;

        for (int i = 0; i < 4; i++)
        {
            int nx = p.first + dx.at(i), ny = p.second + dy.at(i);
            if (nx < 0 || nx >= H || ny < 0 || ny >= W || c.at(nx).at(ny) == 'X' || d.at(nx).at(ny) != -1)
                continue;
            que.push(make_pair(nx, ny));
            d.at(nx).at(ny) = d.at(p.first).at(p.second) + 1;
        }
    }
    return d.at(gx).at(gy);
}

int main()
{
    cin >> H >> W >> N;
    c.resize(H);
    d.resize(H, vector<int>(W));

    for (string &p : c)
        cin >> p;
    int dist = 0;
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            dist += bfs('S', to_string(i + 1).at(0));
        }
        else
        {
            dist += bfs(to_string(i).at(0), to_string(i + 1).at(0));
        }
    }
    cout << dist << endl;
}
