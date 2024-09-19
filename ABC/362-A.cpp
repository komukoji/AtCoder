#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, T, A;
    cin >> N >> T >> A;
    int rem = N-(T + A);
    if (T>A){
        if(T>A+rem){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    else{
        if (A > T + rem)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
