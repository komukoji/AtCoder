#include <bits/stdc++.h>
using namespace std;
//TODO
int main()
{
    int N;
    cin >> N;
    vector<vector<vector<int>>> A(N, vector<vector<int>>(N, vector<int>(N)));
    for (int i = 0; i < N * N * N; i++)
    {
        int xi = i / (N * N);
        int zi = i % N;
        int yi = (i % (N * N)) / N;
        cin >> A.at(xi).at(yi).at(zi);
    }

    int Q;
    cin >> Q;
    for (int qi = 0; qi < Q;qi++){
        long sum = 0;
        int Lxi, Rxi, Lyi, Ryi, Lzi, Rzi;
        cin >> Lxi >> Rxi >> Lyi >> Ryi >> Lzi >> Rzi;
        for (int xi = Lxi - 1; xi <= Rxi-1;xi++){
            for (int yi = Lyi - 1; yi <= Ryi - 1; yi++)
            {
                for (int zi = Lzi - 1; zi <= Rzi - 1; zi++)
                {
                    sum += A.at(xi).at(yi).at(zi);
                }
            }
        }
        cout << sum << endl;
    }
}
