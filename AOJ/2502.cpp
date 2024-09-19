#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<int> s(n), l(n), p(n);
    for (int i = 0; i < n;i++){
        cin >> s.at(i) >> l.at(i) >> p.at(i);
    }
    // i番目のフレーズを考慮、長さjのメロディに対する最大価値
    vector<vector<int>> dp(n+1, vector<int>(400, -1));
    dp.at(0).at(0) = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 394;j++){
            for (int len = s.at(i); len <= l.at(i);len++){
                if ( j-len>=0){
                    dp.at(i + 1).at(j) = max(dp.at(i + 1).at(j), max(dp.at(i).at(j), dp.at(i + 1).at(j - len) + p.at(i)));
                }
                else{
                    dp.at(i + 1).at(j) = max(dp.at(i + 1).at(j), dp.at(i).at(j));
                }
            }
        }
    }

    int m;
    cin >> m;
    vector<int> w(m);
    for(int &p:w){
        cin >> p;
    }
    bool can = true;
    for (int i = 0; i < m; i++)
    {
        if(dp.at(n).at(w.at(i)) == -1){
            can = false;
        }
    }
    if(can){
        for (int i = 0; i < m;i++){
            cout << dp.at(n).at(w.at(i)) << endl;
        }
    }
    else{
        cout << -1 << endl;
    }
}
