#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    // set<string> code;
    // for (int i = 0; i < N; i++)
    // {
    //     string test = "";
    //     test.push_back(S.at(i));
    //     for (int j = i + 1; j < N; j++)
    //     {
    //         test.push_back(S.at(j));
    //         for (int k = j + 1; k < N; k++)
    //         {
    //             test.push_back(S.at(k));
    //             code.insert(test);
    //             test.pop_back();
    //         }
    //         test.pop_back();
    //     }
    // }

    int cnt = 0;
    for (int i = 0; i < 1000; i++)
    {
        vector<int> kurai(0);
        kurai.push_back(i / 100);
        kurai.push_back(i / 10 % 10);
        kurai.push_back(i % 10);

        int k = 0;
        for (int j = 0; j < N; j++)
        {
            if (S.at(j) == kurai.at(k) + '0')
            {
                k++;
            }
            if (k == 3)
            {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
}
