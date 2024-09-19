#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        string X, Y;
        cin >> X >> Y;
        int xl = X.size();
        int yl = Y.size();

        //xi文字目、yi文字目までの最長共通部分列の長さ
        vector<vector<int>> dp(xl + 1, vector<int>(yl + 1, 0));
        for (int xi = 0; xi < xl;xi++){
            for (int yi = 0; yi < yl;yi++){
                if(X.at(xi) == Y.at(yi)){
                    dp.at(xi + 1).at(yi + 1) = dp.at(xi).at(yi) + 1;
                }
                else{
                    dp.at(xi + 1).at(yi + 1) = max(dp.at(xi + 1).at(yi), dp.at(xi).at(yi + 1));
                }
            }
        }
        cout << dp.at(xl).at(yl) << endl;
    }
}
