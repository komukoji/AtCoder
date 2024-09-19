#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> island(M);
    for (size_t i = 0; i < M; i++)
    {
        cin >> island.at(i).second >> island.at(i).first;
    }
    sort(island.begin(), island.end());
    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < M; i++)
    {
        if (tmp <= island.at(i).second)
        {
            tmp = island.at(i).first;
            ans++;
        }
    }
    cout << ans;
}