#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    cout << min(A * X + B * Y, min(2 * C * max(X, Y), 2 * C * min(X, Y) + A * (X - min(X, Y)) + B * (Y-min(X, Y))));
}
