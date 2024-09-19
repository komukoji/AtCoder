#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &p:A){
        cin >> p;
    }
    //i問目まで見てそこまで解いた問題数の偶奇で最大得点
    vector<vector<long long>> dp(N + 1, vector<long long>(2, 0));
    for (int i = 0; i < N;i++){
        for (int j = 0; j < 2;j++){
            if(i==0 && j == 1){
                continue;
            }
            if(j%2==0){
                dp.at(i + 1).at((j + 1) % 2) = max(dp.at(i).at(j) + A.at(i),dp.at(i).at((j+1)%2));
            }
            else{
                dp.at(i + 1).at((j + 1) % 2) = max(dp.at(i).at(j) + 2 * A.at(i), dp.at(i).at((j + 1) % 2));
            }
        }
    }
    cout << max(dp.at(N).at(0), dp.at(N).at(1)) << endl;
}
