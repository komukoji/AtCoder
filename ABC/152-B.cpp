#include <bits/stdc++.h>
using namespace std;



int main(){
    int a, b;
    cin >> a >> b;
    string Sa, Sb ;
    Sa.assign(b, to_string(a).at(0));
    Sb.assign(a, to_string(b).at(0));
    cout << min(Sa, Sb);
}