#include <bits/stdc++.h>
using namespace std;

// スタート地点から到達可能な座標のreachedをtrueにする
void reach(vector<string> &board, vector<vector<bool>> &reached, int x, int y)
{
    if (board.at(x).at(y) == 'o')
    {
        reached.at(x).at(y) = true;
    }
    if (reached.at(x).at(y))
    {
        if (x >= 1 && !reached.at(x - 1).at(y))
        {
            reach(board, reached, x - 1, y); // 左に進む
        }
        if (y >= 1 && !reached.at(x).at(y - 1))
        {
            reach(board, reached, x, y - 1); // 上に進む
        }
        if (x <= 8 && !reached.at(x + 1).at(y))
        {
            reach(board, reached, x + 1, y); // 右に進む
        }
        if (y <= 8 && !reached.at(x).at(y + 1))
        {
            reach(board, reached, x, y + 1); // 下に進む
        }
    }
    return;
}

bool solo_island(vector<string> &board)
{
    vector<vector<bool>> reached(10, vector<bool>(10, false));
    int x, y;
    bool found = false;
    for (int i = 0; i < 10; i++)
    { // 一つ陸地をみつける
        for (int j = 0; j < 10; j++)
        {
            if (board.at(i).at(j) == 'o')
            {
                x = i;
                y = j;
                found = true;
                break;
            }
        }
        if (found)
        {
            break;
        }
    }
    reach(board, reached, x, y);
    found = false;
    bool island = true;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (board.at(i).at(j) == 'o' && !reached.at(i).at(j))
            {
                island = false;
                found = true;
                break;
            }
        }
        if (found)
        {
            break;
        }
    }
    return island;
}

int main()
{
    // 地図を入力
    vector<string> board(10);
    for (int i = 0; i < 10; i++)
    {
        cin >> board.at(i);
    }

    bool island = false;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (board.at(i).at(j) == 'x')
            {
                board.at(i).at(j) = 'o'; // 一つ陸地にする
                if (solo_island(board))
                {
                    island = true;
                }
                board.at(i).at(j) = 'x';
            }
            if (island)
            {
                break;
            }
        }
        if (island)
        {
            break;
        }
    }

    if (island)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}