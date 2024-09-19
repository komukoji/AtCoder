#include <bits/stdc++.h>
using namespace std;

void candy(int &sum, int routesum, int x, int y, vector<vector<int>> &A)
{
    routesum += A.at(x).at(y);
    if (x == A.size() - 1 && y == A.at(0).size() - 1)
    {
        sum = max(sum, routesum);
    }

    if (x < A.size() - 1)
    {
        candy(sum, routesum, x + 1, y, A);
    }
    if (y < A.at(0).size() - 1)
    {
        candy(sum, routesum, x, y + 1, A);
    }
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> A(2, vector<int>(N));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A.at(i).at(j);
        }
    }

    int sum = 0;
    candy(sum, 0, 0, 0, A);
    cout << sum << endl;
}
