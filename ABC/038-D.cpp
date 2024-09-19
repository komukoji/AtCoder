#include <bits/stdc++.h>
using namespace std;
//TODO LISを作る解法にDPに使うらしいので一旦放置
int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> box(N);
    for (auto &p : box)
    {
        cin >> p.first >> p.second;
    }
    sort(box.begin(), box.end());
    int ans = 0;
    int h = 0, w = 0;
    for (int i = 0; i < N; i++)
    {
        if (box.at(i).first > h && box.at(i).second>w)
        {
            ans++;
            h = box.at(i).first;
            w = box.at(i).second;
        }
    }
    cout << ans;
}