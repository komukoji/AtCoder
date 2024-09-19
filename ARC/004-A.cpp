#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++)
    {
        cin >> x.at(i) >> y.at(i);
    }

    int dist = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int d = (x.at(j) - x.at(i)) * (x.at(j) - x.at(i)) + (y.at(j) - y.at(i)) * (y.at(j) - y.at(i));
            dist = max(dist, d);
        }
    }

    cout << sqrt(dist) << endl;
}
