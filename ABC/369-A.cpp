#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}

int main(){
    int A, B;
    cin >> A >> B;
    if (A==B){
        cout << 1 << endl;
    }
    else if (A !=B && abs(A-B)%2 == 1){
        cout << 2 << endl;
    }
    else if (A!=B && abs(A-B)%2==0){
        cout << 3 << endl;
    }
}
