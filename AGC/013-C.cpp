#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, L, T;
    cin >> N >> L >> T;
    vector<int> X(N), W(N);

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> X.at(i) >> W.at(i);
    }

    for (int i = 0; i < N; i++)
    {
        if (W.at(i) == 1)
        {
            X.at(i) += T;
            count += X.at(i) / L;
            X.at(i) %= L;
        }
        else if (W.at(i) == 2)
        {
            X.at(i) -= T;
            if (X.at(i) < 0)
            {
                int minus = (-X.at(i) + L - 1) / L;
                count -= minus;
                X.at(i) += minus * L;
            }
        }
    }

    if (count > 0)
        count %= N;
    else
        count += (-count + N - 1) / N * N;

    sort(X.begin(), X.end());
    if (count > 0)
    {
        for (int i = count; i < N; i++)
        {
            cout << X.at(i) << endl;
        }
        for (int i = 0; i < count; i++)
        {
            cout << X.at(i) << endl;
        }
    }
    else if (count < 0)
    {
        for (int i = N + count; i < N; i++)
        {
            cout << X.at(i) << endl;
        }
        for (int i = 0; i < N + count; i++)
        {
            cout << X.at(i) << endl;
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            cout << X.at(i) << endl;
        }
    }
}