#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> s(M,vector<int>(0));
    for (int i = 0; i < M;i++){
        int k;
        cin >> k;
        for (int j = 0; j < k; j++){
            int sij;
            cin >> sij;
            s.at(i).push_back(sij);
        }
    }
    vector<int> p(M);
    for (int &m:p){
        cin >> m;
    }

    int ans = 0;
    for (int i = 0; i < (1 << N); i++)
    {
        bool all = true;
        for (int j = 0; j < M;j++){
            int sum = 0;
            for (int k = 0; k < s.at(j).size(); k++){
                if (i & (1 << (s.at(j).at(k)-1))){
                    sum++;
                }
            }
            if (sum%2!=p.at(j)){
                all = false;
            }
        }
        if(all){
            ans++;
        }
    }
    cout << ans << endl;
}
