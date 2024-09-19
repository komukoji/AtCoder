#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int D, N;
    cin >> D >> N;
    vector<int> Temp(D);
    for (int &p : Temp)
    {
        cin >> p;
    }
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i) >> B.at(i) >> C.at(i);
    }
    vector<vector<int>> dp(D, vector<int>(N, -1)); // i日目に服jを選んだ時の最大価値
    for (int i = 0; i < N; i++)                    // 初日の価値0
    {
        if (A.at(i) <= Temp.at(0) && Temp.at(0) <= B.at(i))
        {
            dp.at(0).at(i) = 0;
        }
    }
    for (int i = 1; i < D; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (A.at(j) > Temp.at(i) || Temp.at(i) > B.at(j))
            { // きれないなら飛ばす
                continue;
            }
            int value = 0;
            int i_cloth = -1;
            for (int k = 0; k < N; k++) // 昨日どの服着れば最大か走査
            {
                if (dp.at(i - 1).at(k) != -1 && value < dp.at(i - 1).at(k) + abs(C.at(j) - C.at(k)))
                {
                    i_cloth = k;
                    value = dp.at(i - 1).at(k) + abs(C.at(j) - C.at(k));
                }
            }
            dp.at(i).at(j) = value;
        }
    }
    int vmax = 0;
    for (int i = 0; i < N; i++)
    {
        if (vmax < dp.at(D - 1).at(i))
        {
            vmax = dp.at(D - 1).at(i);
        }
    }
    cout << vmax << endl;
}
