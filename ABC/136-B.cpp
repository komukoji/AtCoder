#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}

int main(){
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        string S = to_string(i);
        if(S.size()%2 == 1){
            ans++;
        }
    }
    cout << ans << endl;
}
