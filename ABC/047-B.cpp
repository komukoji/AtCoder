#include <bits/stdc++.h>
using namespace std;

int main()
{
    int W, H, N;
    cin >> W >> H >> N;
    int maxx = W, maxy = H, minx = 0, miny = 0;
    for (int i = 0; i < N; i++)
    {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1 && minx < x)
            minx = x;
        if (a == 2 && maxx > x)
            maxx = x;
        if (a == 3 && miny < y)
            miny = y;
        if (a == 4 && maxy > y)
            maxy = y;
    }
    if (maxx < minx || maxy < miny)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << (maxx - minx) * (maxy - miny) << endl;
    }
}