#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<char> a(H * W);
    for (int i = 0; i < a.size(); i++)
    {
        cin >> a.at(i);
    }
    for (int i = 0; i < W + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < H; i++)
    {
        cout << "#";
        for (int j = 0; j < W; j++)
        {
            cout << a.at(i * W + j);
        }
        cout << "#" << endl;
    }
    for (int i = 0; i < W + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
}