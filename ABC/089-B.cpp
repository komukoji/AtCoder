#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    bool Yellow = false;
    for (int i = 0; i < N; i++)
    {
        string si;
        cin >> si;
        if (si == "Y")
        {
            Yellow = true;
        }
    }
    if (Yellow)
    {
        cout << "Four" << endl;
    }
    else
    {
        cout << "Three" << endl;
    }
}