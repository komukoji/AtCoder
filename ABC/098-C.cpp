#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> east(N + 1, 0);
    vector<int> west(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        east.at(i + 1) = east.at(i);
        west.at(i + 1) = west.at(i);

        if (S.at(i) == 'E')
            east.at(i + 1)++;
        if (S.at(i) == 'W')
            west.at(i + 1)++;
    }

    int ans = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        int count = (west.at(i) - west.at(0)) + (east.at(N) - east.at(i + 1));
        ans = min(ans, count);
    }
    cout << ans << endl;
}