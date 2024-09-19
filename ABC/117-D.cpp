#include <bits/stdc++.h>
using namespace std;

// 二進数の最大桁数(余裕あり)
const int MAX_DIGIT = 50;

int main()
{
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> A(N);
    for (long long &p : A)
    {
        cin >> p;
    }

    // 左からi桁目のbit、Kにできるだけbitを合わせた場合とK未満確定の場合でそれぞれ最大価値
    vector<vector<long long>> dp(MAX_DIGIT + 1, vector<long long>(2, -1)); // あとで0or1に決めるので、最初は-1に初期化
    dp.at(0).at(0) = 0;
    for (int i = 0; i < MAX_DIGIT; i++)
    { // 左からi桁目
        long long mask = 1LL << (MAX_DIGIT - i - 1);

        // Aでi桁目に立っているビットの数,i桁目が0ならこの数分価値増える
        int num = 0;
        for (int j = 0; j < N; j++)
        {
            if (A.at(j) & mask)
            {
                num++;
            }
        }

        for (int smaller = 0; smaller < 2; smaller++)
        {
            for (int x = 0; x <= (smaller ? 1 : ((K&mask) ? 1 : 0)); x++)
            {
                if (dp.at(i).at(smaller) == -1)
                { // dp.at(0).at(1)は-1なので飛ばす
                    continue;
                }
                // 未満確定→未満確定,i桁目は0でも1でもOK
                if (smaller)
                {
                    dp.at(i + 1).at(1) = max(dp.at(i + 1).at(1), dp.at(i).at(1) + mask * max(num, N - num));
                }
                else
                { // 未満未確定
                    if (x == 0 && (K & mask))
                    { // →未満確定
                        dp.at(i + 1).at(1) = max(dp.at(i + 1).at(1), dp.at(i).at(0) + mask * num);
                    }
                    else if ((K & mask)&& x ==1)
                    { // →未満未確定、i桁目は1
                        dp.at(i + 1).at(0) = max(dp.at(i + 1).at(0), dp.at(i).at(0) + mask * (N - num));
                    }
                    else if(x==0)
                    {
                        dp.at(i + 1).at(0) = max(dp.at(i + 1).at(0), dp.at(i).at(0) + mask * num);
                    }
                }
            }
        }
    }
    cout << max(dp.at(MAX_DIGIT).at(0), dp.at(MAX_DIGIT).at(1)) << endl;
}
