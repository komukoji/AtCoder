#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int li, ri;
        cin >> li >> ri;
        sum += ri - li + 1;
    }
    cout << sum << endl;
}