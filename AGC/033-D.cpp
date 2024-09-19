#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}

//TODO 尺取り法
int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for (string &p:A){
        cin >> p;
    }

    /*普通に組むとdp[ h1 ][ h2 ][ w1 ][ w2 ] := 長方形領域の [h1, h2) × [w1, w2) の複雑度
    だけど計算量が以上にかかる

    dp1[ h1 ][ h2 ][ w1 ][ k ] := 区間 [h1, h2) × [w1, w2) の複雑度が k 以下となる最大の w2
    dp2[ h1 ][ w1 ][ w2 ][ k ] := 区間 [h1, h2) × [w1, w2) の複雑度が k 以下となる最大の h2
    にすればよい
     */
    // i行j列までの複雑さ,kはたかだかlog_2H+log_2Wぐらい→16ぐらい
    vector<vector<vector<vector<int>>>> dp1(200, vector<vector<vector<int>>> (200, vector<vector<int>> (200, vector<int> (16,0))));
    vector<vector<vector<vector<int>>>> dp2(200, vector<vector<vector<int>>>(200, vector<vector<int>>(200, vector<int>(16, 0))));
}
