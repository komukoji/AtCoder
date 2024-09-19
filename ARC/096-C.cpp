#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    if (A + B < 2 * C)
    {
        cout << A * X + B * Y << endl;
    }
    else if (2 * C < A && X > Y)
    {
        cout << 2 * C * X << endl;
    }
    else if (2 * C < B && Y > X)
    {
        cout << 2 * C * Y << endl;
    }
    else
    {
        cout << 2 * C * min(X, Y) + A * (X - min(X, Y)) + B * (Y - min(X, Y)) << endl;
    }
}