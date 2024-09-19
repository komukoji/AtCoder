#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;
    vector<string> S(N);
    for (string &p : S)
        cin >> p;

    sort(S.begin(), S.end());
    for (string p : S)
        cout << p;
}