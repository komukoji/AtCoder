#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int &p : a)
        cin >> p;

    map<int, int> arr;
    for (int p : a)
    {
        arr[p - 1]++;
        arr[p]++;
        arr[p + 1]++;
    }

    int maxnum = 0;
    for (int i = 0; i < 100000; i++)
    {
        maxnum = max(maxnum, arr[i]);
    }
    cout << maxnum << endl;
}