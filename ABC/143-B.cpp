#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> d(N);
    for (int &p : d)
    {
        cin >> p;
    }
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            sum += d.at(i) * d.at(j);
        }
    }
    cout << sum;
}