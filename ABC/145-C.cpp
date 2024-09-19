#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> town(N);
    for (pair<int, int> &p : town)
    {
        int x, y;
        cin >> x >> y;
        p = make_pair(x, y);
    }
    vector<int> junban(N);
    for (int i = 0; i < N; i++)
    {
        junban.at(i) = i;
    }
    int cnt = 0;
    double sum = 0;
    do
    {
        cnt++;
        for (int k = 0; k < N - 1; k++)
        {
            int cx = town.at(junban.at(k)).first;
            int cy = town.at(junban.at(k)).second;
            int nx = town.at(junban.at(k + 1)).first;
            int ny = town.at(junban.at(k + 1)).second;
            sum += sqrt((nx - cx) * (nx - cx) + (ny - cy) * (ny - cy));
        }
    } while (next_permutation(junban.begin(), junban.end()));
    cout << setprecision(10) <<(sum / (double)cnt) << endl;
}
