#include <bits/stdc++.h>
using namespace std;

double distance(vector<int> x, vector<int> y)
{
    int dd = 0;
    for (int i = 0; i < x.size(); i++)
    {
        dd += (x.at(i) - y.at(i)) * (x.at(i) - y.at(i));
    }
    return sqrt(dd);
}

int main()
{
    int N, D;
    cin >> N >> D;
    vector<vector<int>> X(N, vector<int>(D));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            cin >> X.at(i).at(j);
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            double d = distance(X.at(i), X.at(j));
            if ((int)d == d)
                count++;
        }
    }
    cout << count << endl;
}
