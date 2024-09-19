#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int &p:A){
        cin >> p;
    }

    for (int i = N - K; i < N;i++){
        cout << A.at(i) << ' ';
    }
    for (int i = 0; i < N - K; i++){
        cout << A.at(i) << ' ';
    }
}
