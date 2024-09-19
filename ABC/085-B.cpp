#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> d(N);
    for (int i = 0; i < d.size(); i++)
    {
        cin >> d.at(i);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (d.at(i) < d.at(j))
            {
                int tmp = d.at(i);
                d.at(i) = d.at(j);
                d.at(j) = tmp;
            }
        }
    }
    int stair = 1;
    for (int i = 1; i < N; i++)
    {
        if (d.at(i) > d.at(i - 1))
        {
            stair++;
        }
    }
    cout << stair << endl;
}