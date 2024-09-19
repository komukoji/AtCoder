#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int a, b;
    for (int i = 0; i < s.size(); i++)
    {
        if (s.at(i) == 'A')
        {
            a = i;
            break;
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s.at(i) == 'Z')
        {
            b = i;
        }
    }
    cout << b - a + 1 << endl;
}