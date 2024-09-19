#include <bits/stdc++.h>
using namespace std;

int main(){
    string N;
    cin >> N;
    int L = N.size();
    // i桁目、未満確定フラグ、1を何回書いたか
    vector<vector<vector<int>>> dp(L+1, vector<vector<int>> (2, vector<int> (L+1,0)));
    dp.at(0).at(0).at(0) = 1;
    for (int i = 0; i < L; i++){
        for (int smaller = 0; smaller < 2;smaller++){
            for (int j = 0; j < L;j++){
                for (int x = 0; x <= (smaller ? 9 : N.at(i) - '0'); x++){
                    if (x == 1)
                    {
                        dp.at(i + 1).at(smaller || x < N.at(i) - '0').at(j+1) += dp.at(i).at(smaller).at(j);
                    }
                    else{
                    dp.at(i + 1).at(smaller || x < N.at(i) - '0').at(j) += dp.at(i).at(smaller).at(j);
                }
            }
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= L;i++){
        sum += (dp.at(L).at(0).at(i) + dp.at(L).at(1).at(i)) * i;
    }
        cout << sum << endl;
}
