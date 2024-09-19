#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<tuple<string, int, int>> rest(N);
    for (int i = 0; i < N; i++)
    {
        cin >> get<0>(rest.at(i)) >> get<1>(rest.at(i));
        get<2>(rest.at(i)) = i + 1;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (get<0>(rest.at(i)) > get<0>(rest.at(j)))
            {
                auto tmp = rest.at(i);
                rest.at(i) = rest.at(j);
                rest.at(j) = tmp;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (get<1>(rest.at(i)) < get<1>(rest.at(j)) && get<0>(rest.at(i)) == get<0>(rest.at(j)))
            {
                auto tmp = rest.at(i);
                rest.at(i) = rest.at(j);
                rest.at(j) = tmp;
            }
        }
    }

    for (auto x : rest)
    {
        cout << get<2>(x) << endl;
    }
}