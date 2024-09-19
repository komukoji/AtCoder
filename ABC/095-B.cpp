#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    vector<int> m(N);
    int res = INT_MAX;
    for (int &p : m)
    {
        cin >> p;
        X -= p;
        res = min(p, res);
    }
    cout << N + X / res << endl;
}