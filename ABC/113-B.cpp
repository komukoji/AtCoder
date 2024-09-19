#include <bits/stdc++.h>
using namespace std;

int main()
{
    double N, T, A;
    cin >> N >> T >> A;
    vector<int> height(N);
    for (int &p : height)
    {
        cin >> p;
    }

    double dif = (double)INT_MAX;
    int res = -1;
    for (int i = 0; i < N; i++)
    {
        double temp = T - height.at(i) * 0.006;
        double pdif = max(A, temp) - min(A, temp);
        if (dif > pdif)
        {
            res = i;
            dif = pdif;
        }
    }
    cout << res + 1 << endl;
}