#include <bits/stdc++.h>
using namespace std;

long long solve(const string &S){
    const int L = S.size();
    // 桁、未満確定フラグ、49が出たか
    // S.at(i)まで調べた結果はdp.at(i+1).に入ることに注意
    vector<vector<vector<long long>>> dp(L+1, vector<vector<long long>>(2, vector<long long>(2, 0)));
    dp.at(0).at(0).at(0) = 1;
    for (int i = 0; i < L; i++){
        for (int smaller=0; smaller < 2;smaller++){
            for (int j=0; j < 2;j++){
                for (int x = 0; x <= (smaller ? 9 : S.at(i)-'0');x++){
                    dp.at(i + 1).at(smaller || x < S.at(i) - '0').at(j || x == 4 || x == 9) += dp.at(i).at(smaller).at(j);
                }
            }
        }
    }
    return dp.at(L).at(0).at(1) + dp.at(L).at(1).at(1);
}

int main(){
    long long A, B;
    cin >> A >> B;
    cout << solve(to_string(B)) - solve(to_string(A - 1)) << endl;
}
