#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int s1l = s1.size();
    int s2l = s2.size();

    vector<vector<int>> dp(s1l + 1, vector<int>(s2l + 1, 0));
    // s1i=0, s2i=1の操作回数は1、0ではない indexは-1から走査が必要！
    for (int s1i = -1; s1i < s1l; s1i++)
    {
        for (int s2i = -1; s2i < s2l; s2i++)
        {
            if (s1i == -1 && s2i == -1)
                continue;
            if (s1i >= 0 && s2i >= 0)//通常
            {
                if (s1.at(s1i) == s2.at(s2i))
                {
                    dp.at(s1i + 1).at(s2i + 1) = min(dp.at(s1i).at(s2i), min(dp.at(s1i + 1).at(s2i) + 1, dp.at(s1i).at(s2i + 1) + 1));
                }
                else
                {
                    dp.at(s1i + 1).at(s2i + 1) = min(dp.at(s1i).at(s2i) + 1, min(dp.at(s1i + 1).at(s2i) + 1, dp.at(s1i).at(s2i + 1) + 1));
                }
            }
            else if(s1i >= 0){//s2i = -1, s1i>=0のとき
                dp.at(s1i + 1).at(s2i + 1) =  dp.at(s1i).at(s2i + 1) + 1;
            }
            else if (s2i >= 0)
            { // s1i = -1, s2i>=0のとき
                dp.at(s1i + 1).at(s2i + 1) = dp.at(s1i+1).at(s2i) + 1;
            }
        }
    }
    cout << dp.at(s1l).at(s2l) << endl;
}
