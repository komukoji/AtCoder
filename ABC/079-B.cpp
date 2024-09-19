#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> L = {2, 1};
    if (N == 0)
        cout << 2 << endl;
    else if (N == 1)
        cout << 1 << endl;
    else
    {
        for (int i = 2; i < N + 1; i++)
        {
            L.push_back(L.at(i - 1) + L.at(i - 2));
        }
        cout << L.at(N) << endl;
    }
}