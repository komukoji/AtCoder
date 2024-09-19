#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    bool kuku = false;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (i * j == N)
                kuku = true;
        }
    }
    if (kuku)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}