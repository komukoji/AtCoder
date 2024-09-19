#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;
    vector<string> key = {};
    for (int i = 0; i < S.size(); i++)
    {
        if (S.at(i) == T.at(0) || S.at(i) == '?')
        {
            bool can = true;
            for (int j = 0; j < T.size(); j++)
            {
                if (i + j >= S.size())
                {
                    can = false;
                    break;
                }
                if (S.at(i + j) != T.at(j) && S.at(i + j) != '?')
                {
                    can = false;
                    break;
                }
            }
            if (can)
            {
                string newkey = S;
                for (int j = 0; j < T.size(); j++)
                {
                    newkey.at(i + j) = T.at(j);
                }
                for (int j = 0; j < S.size(); j++)
                {
                    if (newkey.at(j) == '?')
                    {
                        newkey.at(j) = 'a';
                    }
                }
                key.push_back(newkey);
            }
        }
    }
    if (key.size())
    {
        sort(key.begin(), key.end());
        cout << key.at(0) << endl;
    }
    else
    {
        cout << "UNRESTORABLE" << endl;
    }
}