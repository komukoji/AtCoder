#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Q;
    cin >> Q;
    map<int, int> balls;
    int species = 0;
    for (int qi = 0; qi < Q; qi++)
    {
        int n, x;
        cin >> n;
        switch (n)
        {
        case 1:
            cin >> x;
            if (!balls.count(x))
            {
                balls[x] = 1;
                species++;
            }
            else if (balls[x] == 0)
            {
                balls[x]++;
                species++;
            }
            else
            {
                balls[x]++;
            }
            break;
        case 2:
            cin >> x;
            balls[x]--;
            if (balls[x] == 0)
            {
                species--;
            }
            break;

        case 3:
            cout << species << endl;
            break;

        default:
            break;
        }
    }
}
