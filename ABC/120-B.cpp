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
    int A, B, K;
    cin >> A >> B >> K;
    vector<int> div(0);
    for (int i = 1; i <= min(A, B); i++)
    {
        if (A % i == 0 && B % i == 0)
        {
            div.push_back(i);
        }
    }
    cout << div.at(div.size()-K) << endl;
}
