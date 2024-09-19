#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &p : A)
    {
        cin >> p;
    }
    int maxdif = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int dif = max(A.at(i), A.at(j)) - min(A.at(i), A.at(j));
            maxdif = max(maxdif, dif);
        }
    }
    cout << maxdif << endl;
}