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
    if (N == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    //前項との差
    vector<int> B(N-1,0);
    for (int i = 0; i < N-1;i++){
        B.at(i) = A.at(i+1) - A.at(i);
    }
    long long ans = N + (N - 1);//一つ・二つは先に足しておく
    long long res = B.at(0);
    long long n=2;
    for (int i = 1; i < N-1; i++)
    {
        if (B.at(i) != res){
            if  (n>=3){
                ans += n * (n + 1) / 2 - n - (n - 1);
            }
            n = 2;
            res = B.at(i);
        }
        else {
            n++;
        }
        if(i == N-2){
            if (n >= 3)
            {
                ans += n * (n + 1) / 2 - n - (n - 1);
            }
        }
    }
    cout << ans << endl;
}
