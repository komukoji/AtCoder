#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}

int main(){
    string S;
    cin >> S;
    int res = 0;
    int ans = 0;
    for (int i = 0; i < S.size();i++){
        if (S.at(i) == 'A' || S.at(i) == 'T' || S.at(i) == 'G' || S.at(i) == 'C'){
            res += 1;
        }
        else
        {
            res = 0;
        }
        chmax(ans, res);
    }
    cout << ans << endl;
}
