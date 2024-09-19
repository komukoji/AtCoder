#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> S(N);
    int M = 0;
    for (string &s : S)
    {
        cin >> s;
        // M = max(M, static_cast<int>(s.size()));
        M = max(int(s.size()), M);
    }
    vector<string> T(M, string(N, '*'));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < S.at(i).size(); j++)
        {
            T.at(j).at(N - 1 - i) = S.at(i).at(j);
        }
    }

    for (int i = 0; i < M; i++)
    {
        while (T.at(i).at(T.at(i).size()-1) == '*'){
            T.at(i).pop_back();
        }
    }

    for (string t : T)
    {
        cout << t << endl;
    }
}
