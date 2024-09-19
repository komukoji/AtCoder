#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> cam(H);
    for (int i = 0; i < H; i++)
    {
        cin >> cam.at(i);
    }

    bool can = true;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (cam.at(i).at(j) == '#')
            {
                bool neigh = false;
                if (i != 0 && cam.at(i - 1).at(j) == '#')
                    neigh = true;
                if (j != 0 && cam.at(i).at(j - 1) == '#')
                    neigh = true;
                if (i != H - 1 && cam.at(i + 1).at(j) == '#')
                    neigh = true;
                if (j != W - 1 && cam.at(i).at(j + 1) == '#')
                    neigh = true;

                if (!neigh)
                    can = false;
            }
        }
    }
    if (can)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}