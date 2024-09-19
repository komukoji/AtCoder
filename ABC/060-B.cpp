#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    bool can = false;
    for (int i = 0; i <= A; i++)
    {
        if ((B * i + C) % A == 0)
            can = true;
    }
    if (can)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}