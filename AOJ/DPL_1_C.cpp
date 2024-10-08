#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;

int main(){
    int N, W;
    cin >> N >> W;
    vector<int> v(N), w(N);
    for (int i = 0; i < N;i++){
        cin >> v.at(i) >> w.at(i);
    }

    vector<vector<int>> dp(N + 1, vector<int>(W + 1,0));
    for (int i = 0; i < N;i++){
        for (int j = 0; j <= W;j++){
            if(j - w.at(i) < 0){
                dp.at(i + 1).at(j) = dp.at(i).at(j);
            }
            else{
                dp.at(i + 1).at(j) = max(dp.at(i).at(j), dp.at(i+1).at(j-w.at(i))+v.at(i));
            }
        }
    }
    cout << dp.at(N).at(W) << endl;
}
