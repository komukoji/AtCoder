#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int &p : A)
        cin >> p;

    vector<int> num(N, 0);
    for (int p : A)
    {
        num.at(p - 1)++;
    }
    sort(num.begin(), num.end(), greater<int>());
    int count = 0;
    int ans = 0;
    for (int i = K; i < N; i++)
    {
        // if (num.at(i))
        //     count++;
        // if (count > K)
            ans += num.at(i);
    }
    cout << ans << endl;
}
