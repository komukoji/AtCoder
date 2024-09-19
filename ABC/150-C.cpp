#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}

int main(){
    int N;
    cin >> N;
    vector<int> P(N), Q(N), junretu(N);
    for (int i = 0; i < N;i++){
        junretu.at(i) = i + 1;
    }
    for (int &p:P){
        cin >> p;
    }
    for (int &p : Q){
        cin >> p;
    }
    int a, b;
    int i = 0;
    do{
        i++;
        bool p_match = true, q_match = true;
        for (int k = 0; k < N;k++){
            if(junretu.at(k) != P.at(k)){
                p_match = false;
            }
            if(junretu.at(k) != Q.at(k)){
                q_match = false;
            }
        }
        if(p_match){
            a = i;
        }
        if(q_match){
            b = i;
        }
    } while (next_permutation(junretu.begin(), junretu.end()));

    cout << abs(a - b) << endl;
}
