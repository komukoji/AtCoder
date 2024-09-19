#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> xyh(N, vector<int>(3));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> xyh.at(i).at(j);
        }
    }

    int ansx, ansy, ansh;
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            int h;
            for (int k = 0; k < N; k++)
            {
                if (xyh.at(k).at(2) != 0)
                {
                    h = xyh.at(k).at(2) + abs(xyh.at(k).at(0) - i) + abs(xyh.at(k).at(1) - j);
                    break;
                }
            }

            bool center = true;
            for (int k = 0; k < N; k++)
            {
                int kh = xyh.at(k).at(2) + abs(xyh.at(k).at(0) - i) + abs(xyh.at(k).at(1) - j);
                if (!(kh == h || (xyh.at(k).at(2) == 0 && kh >= h)))
                    center = false;
            }
            if (center)
            {
                ansx = i;
                ansy = j;
                ansh = h;
            }
        }
    }
    cout << ansx << " " << ansy << " " << ansh << endl;
}