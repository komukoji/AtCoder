#include <bits/stdc++.h>
using namespace std;



int main(){
    int N;
    cin >> N;
    bool can = true;
    for (int i = 0; i < N;i++){
        int A;
        cin >> A;
        if(A%2==0){
            if(A%3!=0&&A%5!=0)
                can = false;
        }
    }
    if(can){
        cout << "APPROVED";
    }
    else{
        cout << "DENIED";
    }
}