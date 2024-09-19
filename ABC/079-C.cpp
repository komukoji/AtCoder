#include <bits/stdc++.h>
using namespace std;

int ctoi(char s)
{
    if (s == '0')
        return 0;
    if (s == '1')
        return 1;
    if (s == '2')
        return 2;
    if (s == '3')
        return 3;
    if (s == '4')
        return 4;
    if (s == '5')
        return 5;
    if (s == '6')
        return 6;
    if (s == '7')
        return 7;
    if (s == '8')
        return 8;
    if (s == '9')
        return 9;
}

string train(string s, vector<string> &checked)
{
    for (string p : checked)
    {
        if (p == s)
            return "";
    }
    checked.push_back(s);
    int sum = ctoi(s.at(0));
    for (int i = 0; i < 3; i++)
    {
        if (s.at(2 * i + 1) == '+')
            sum += ctoi(s.at(2 * i + 2));
        if (s.at(2 * i + 1) == '-')
            sum -= ctoi(s.at(2 * i + 2));
    }
    // ベースケース
    if (sum == 7)
        return s + "=7";

    // 再帰ステップ
    bool allminus = true;
    for (int i = 0; i < 3; i++)
    {
        if (s.at(2 * i + 1) == '+')
        {
            allminus = false;
            s.at(2 * i + 1) = '-';
            string ans = train(s, checked);
            if (ans != "")
                return ans;
            s.at(2 * i + 1) = '+';
        }
    }
    if (allminus)
        return "";
}

int main()
{
    string s;
    cin >> s;
    string S = "";
    for (int i = 0; i < 4; i++)
    {
        if (i > 0)
            S += "+";
        S += s.at(i);
    }
    vector<string> checked = {};
    cout << train(S, checked) << endl;
}
