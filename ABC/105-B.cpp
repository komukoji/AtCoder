#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    bool possible = false;
    while (N >= 0)
    {
        if (N % 4 == 0)
            possible = true;
        N -= 7;
    }
    if (possible)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
