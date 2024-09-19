#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> alpha(26, true);

    for (char p : s)
    {
        alpha.at(p - 'a') = false;
    }

    for (int i; i < 26; i++)
    {
        if (alpha.at(i))
        {
            cout << (char)('a' + i) << endl;
            break;
        }
        if (i == 25)
            cout << "None" << endl;
    }
}