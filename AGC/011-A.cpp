#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, C, K;
    cin >> N >> C >> K;
    vector<int> time(N);
    for (int &p : time)
        cin >> p;

    int count = 1;
    sort(time.begin(), time.end());
    vector<int> bus = {time.at(0)};
    for (int i = 1; i < N; i++)
    {
        if (bus.size() == C)
        {
            count++;
            bus = {time.at(i)};
        }
        else if (time.at(i) - bus.at(0) > K)
        {
            count++;
            bus = {time.at(i)};
        }
        else
        {
            bus.push_back(time.at(i));
        }
    }
    cout << count << endl;
}