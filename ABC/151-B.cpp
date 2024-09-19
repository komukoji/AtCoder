#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K, M;
    cin >> N >> K >> M;
    vector<int> A(N);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> A.at(i);
    }
    if (N * M - accumulate(A.begin(), A.end() - 1, 0) > K )
    {
        cout << -1;
    }
    else if ( N * M - accumulate(A.begin(), A.end() - 1, 0) < 0){
        cout << 0;
    }
    else
    {
        cout << N * M - accumulate(A.begin(), A.end() - 1, 0);
    }
}