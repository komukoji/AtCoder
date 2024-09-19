#include <bits/stdc++.h>
using namespace std;

int ctoi(char c)
{
    if (c == '0')
        return 0;
    if (c == '1')
        return 1;
    if (c == '2')
        return 2;
    if (c == '3')
        return 3;
    if (c == '4')
        return 4;
    if (c == '5')
        return 5;
    if (c == '6')
        return 6;
    if (c == '7')
        return 7;
    if (c == '8')
        return 8;
    if (c == '9')
        return 9;
}

void arrsum(string s, vector<string> &checked, int64_t &sum)
{
    // すでに見つけたなら終了
    bool found = false;
    for (string p : checked)
    {
        if (p == s)
            found = true;
    }
    if (found)
        return;

    // 見つけた
    checked.push_back(s);

    // 計算
    int64_t num = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s.at(i) == '+')
        { // ＋が来たら足し算に代入
            sum += num;
            num = 0L;
        }
        else
        { // それ以外はそれまでの数を10倍しておきその数を加える
            num = num * 10 + ctoi(s.at(i));
        }
        if (i == s.size() - 1)
            sum += num;
    }

    // 再帰処理
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s.at(i) != '+' && s.at(i + 1) != '+')
        {
            string str = "";
            for (int j = 0; j < s.size(); j++)
            {
                str += s.at(j);
                if (i == j)
                    str += '+';
            }
            arrsum(str, checked, sum);
        }
    }
}

int64_t allsum(string n)
{
    int64_t sum = 0;
    vector<string> checked = {};
    arrsum(n, checked, sum);
    return sum;
}

int main()
{
    string n;
    cin >> n;
    cout << allsum(n) << endl;
}
