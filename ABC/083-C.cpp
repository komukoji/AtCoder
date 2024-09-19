#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long X, Y;
    cin >> X >> Y;
    vector<long long> A(0);
    A.push_back(X);
    int i = 0;
    while (true)
    {
        if (A.at(i) * 2 <= Y)
        {
            A.push_back(A.at(i) * 2);
            i++;
        }
        else
        {
            break;
        }
    }
    cout << A.size() << endl;
}