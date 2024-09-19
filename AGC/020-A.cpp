#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    // if(A==1&&B==2)cout << "Borys" << endl;
    if ((B - A - 1) % 2 == 0)
        cout << "Borys" << endl;
    else
        cout << "Alice" << endl;
}