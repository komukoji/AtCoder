#include <bits/stdc++.h>
using namespace std;

void cookmeat(int &ans, int i, int sum1, int sum2, vector<int> &time, int &N)
{
    if (i == N)
    {
        ans = min(ans, max(sum1, sum2));
        return;
    }
    cookmeat(ans, i + 1, sum1 + time.at(i), sum2, time, N);
    cookmeat(ans, i + 1, sum1, sum2 + time.at(i), time, N);
}

int main()
{
    int N;
    cin >> N;
    vector<int> t(N);
    int summax = 0;
    for (int &p : t)
    {
        cin >> p;
        summax += p;
    }
    cookmeat(summax, 0, 0, 0, t, N);
    cout << summax << endl;
}