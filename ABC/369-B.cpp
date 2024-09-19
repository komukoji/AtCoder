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
    vector<int> A(N);
    vector<string> S(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i) >> S.at(i);
    }
    int nowL = -1, nowR = -1;
    for (int i = 0; i < N; i++)
    {
        if (S.at(i) == "L")
        {
            nowL = A.at(i);
            break;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (S.at(i) == "R")
        {
            nowR = A.at(i);
            break;
        }
    }
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (S.at(i) == "L")
        {
            sum += abs(A.at(i) - nowL);
            nowL = A.at(i);
        }
        if (S.at(i) == "R")
        {
            sum += abs(A.at(i) - nowR);
            nowR = A.at(i);
        }
    }
    cout << sum << endl;
}
