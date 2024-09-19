#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    string S;
    for (int i = 0; i < H; i++)
    {
        string Si;
        cin >> Si;
        S += Si;
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int count = 0;
            if (S.at(i * W + j) == '.')
            { // 爆弾じゃない場所
                if (i > 0 && j > 0 && S.at(i * W + j - W - 1) == '#')
                { // 左上
                    count++;
                }
                if (i > 0 && S.at(i * W + j - W) == '#')
                { // 上
                    count++;
                }
                if (i > 0 && j < W - 1 && S.at(i * W + j - W + 1) == '#')
                { // 右上
                    count++;
                }
                if (j > 0 && S.at(i * W + j - 1) == '#')
                { // 左
                    count++;
                }
                if (j < W - 1 && S.at(i * W + j + 1) == '#')
                { // 右
                    count++;
                }
                if (i < H - 1 && j > 0 && S.at(i * W + j + W - 1) == '#')
                { // 左下
                    count++;
                }
                if (i < H - 1 && S.at(i * W + j + W) == '#')
                { // 下
                    count++;
                }
                if (i < H - 1 && j < W - 1 && S.at(i * W + j + W + 1) == '#')
                { // 右下
                    count++;
                }
                cout << count;
            }
            else
            { // 爆弾はそのまま出力
                cout << S.at(i * W + j);
            }
        }
        cout << endl;
    }
}