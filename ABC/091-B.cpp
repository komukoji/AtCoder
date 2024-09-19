#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> blue(N);
    for (string &p : blue)
        cin >> p;
    int M;
    cin >> M;
    vector<string> red(M);
    for (string &p : red)
        cin >> p;

    int maxpoint = 0;
    for (string p : blue)
    {
        int point = 0;
        for (string q : blue)
        {
            if (p == q)
                point++;
        }
        for (string q : red)
        {
            if (p == q)
                point--;
        }
        maxpoint = max(maxpoint, point);
    }
    cout << maxpoint << endl;
}