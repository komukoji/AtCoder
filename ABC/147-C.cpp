#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}


int bool_honest(bool honest){
    if(honest){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int N;
    cin >> N;
    vector<vector<pair<int, int>>> As(N, vector<pair<int, int>> (0));
    for (int i=0; i < N;i++){
        int A;
        cin >> A;
        for (int j = 0; j < A;j++){
            int x, y;
            cin >> x >> y;
            x--;
            As.at(i).push_back(make_pair(x, y));
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << N); i++)//正直ならbitがたつ
    {
        bool can = true;
        int sum = 0;
        for (int j = 0; j < N;j++){//j人目がクエリに沿っているか
            if(i&(1 << j)){//j人目が正直者の時
                sum++;
                bool honest = true;
                for (int k = 0; k < As.at(j).size();k++){
                    if (bool_honest(i&(1 << As.at(j).at(k).first))!=As.at(j).at(k).second){//嘘言ってたら不成立
                        honest = false;
                    }
                }
                if(!honest){
                    can = false;
                    break;
                }
            }
            else{//j人目が嘘つきの時
                bool liar = false;
                for (int k = 0; k < As.at(j).size();k++){
                    if (bool_honest(i & (1 << As.at(j).at(k).first)) != As.at(j).at(k).second){//嘘いっってたら嘘つきで成立
                        liar = true;
                    }
                }
                if(!liar){
                    can = false;
                    break;
                }
            }
        }
        if(can){
            chmax(ans, sum);
        }
    }
    cout << ans << endl;
}
