#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> c(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> c.at(i).at(j);
        }
    }

    bool ans = true;

    for (int i = 0; i < 3; i++)
    { // 横のライン
        bool possible = false;
        if (c.at(i).at(0) - c.at(0).at(0) == c.at(i).at(1) - c.at(0).at(1) &&
            c.at(i).at(0) - c.at(0).at(0) == c.at(i).at(2) - c.at(0).at(2))
            possible = true;
        if (!possible)
            ans = false;
    }

    for (int i = 0; i < 3; i++)
    { // 縦のライン
        bool possible = false;
        if (c.at(0).at(i) - c.at(0).at(0) == c.at(1).at(i) - c.at(1).at(0) &&
            c.at(0).at(i) - c.at(0).at(0) == c.at(2).at(i) - c.at(2).at(0))
            possible = true;
        if (!possible)
            ans = false;
    }

    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}