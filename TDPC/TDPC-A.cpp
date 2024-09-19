#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> p(N);
    for (int &m : p)
    {
        cin >> m;
    }
    int M = 100;
    vector<vector<int>> dp(N + 1, (vector<int>(N * M + 1, 0)));//i問まで解いたとき、j点を取れるか
    dp.at(0).at(0) = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N * M + 1; j++)
        {
            //dp.at(i + 1).at(j) = dp.at(i).at(j);
            //dp.at(i + 1).at(j) |= (j - p.at(i) >= 0 ? dp.at(i).at(j - p.at(i)) : 0);
            if(j-p.at(i)>=0){
                dp.at(i + 1).at(j) = dp.at(i).at(j-p.at(i)) || dp.at(i).at(j);
            }
            else{
                dp.at(i + 1).at(j) = dp.at(i).at(j);
            }
        }
    }
    cout << accumulate(dp.at(N).begin(), dp.at(N).end(), 0) << endl;
}
