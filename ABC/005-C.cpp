#include <bits/stdc++.h>
using namespace std;

int main(){
    int T, N;
    cin >> T >> N;
    vector<int> A(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> A.at(i);
    }
    int M;
    cin >> M;
    vector<int> B(M);
    for (size_t i = 0; i < M; i++)
    {
        cin >> B.at(i);
    }
    bool can = true;
    int rem = 0;
    for (size_t i = 0; i < M; i++)
    {
        bool can2 = false;
        for (size_t j = rem; j < N; j++)
        {
            if (A.at(j) >= B.at(i) - T&&A.at(j)<=B.at(i))
            {
                rem = ++j;
                can2 = true;
                break;
            }
        }
        if(!can2){
            can = false;
            break;
        }
    }
    if(can){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
}