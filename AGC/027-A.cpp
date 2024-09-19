#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, x;
    cin >> N >> x;
    vector<int> candy(N);
    for (int &p : candy)
        cin >> p;

    int sum = 0;
    sort(candy.begin(), candy.end());
    int ans;
    for (int i = 0; i < N; i++)
    {
        sum += candy.at(i);
        if (sum == x)
        {
            ans = i + 1;
            break;
        }
        if (sum > x)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}