#include <bits/stdc++.h>
using namespace std;

int ranksum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    int N;
    cin >> N;
    int minsum = INT_MAX;
    for (int i = 1; i < N; i++)
    {
        int sum = ranksum(i) + ranksum(N - i);
        minsum = min(sum, minsum);
    }
    cout << minsum << endl;
}