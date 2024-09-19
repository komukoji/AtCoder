#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> town(N, 0);
    for (int i = 0; i < M; i++)
    {
        int Ai, Bi;
        cin >> Ai >> Bi;
        town.at(Ai - 1)++;
        town.at(Bi - 1)++;
    }
    for (int i = 0; i < N; i++)
    {
        cout << town.at(i) << endl;
    }
}