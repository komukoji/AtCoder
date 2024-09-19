#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;
    for (int i = 0; i < S.size(); i++)
    {
        if (S.at(i) + N > 'Z')
        {
            cout << (char)(S.at(i) + N - 26);
        }
        else
        {
            cout << (char)(S.at(i) + N);
        }
    }
}