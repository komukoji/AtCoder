#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(3 * N);
    for (int &p : a)
        cin >> p;

    sort(a.begin(), a.end(), greater<int>());
    int long sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += a.at(2 * i + 1);
    }
    cout << sum << endl;
}