#include <bits/stdc++.h>
using namespace std;

long long mincount(long long sum, long long start, vector<long long> &a)
{
    long long count = start;
    for (int i = 1; i < a.size(); i++)
    {
        if (sum > 0)
        {
            sum += a.at(i);
            while (sum >= 0)
            {
                sum--;
                count++;
            }
        }
        else
        {
            sum += a.at(i);
            while (sum <= 0)
            {
                sum++;
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int N;
    cin >> N;
    vector<long long> a(N);
    for (long long &p : a)
        cin >> p;

    long long count;
    if (a.at(0) > 0)
    {
        count = min(mincount(-1, a.at(0) + 1, a), mincount(a.at(0), 0, a));
    }
    else if (a.at(0) < 0)
    {
        count = min(mincount(1, -a.at(0) + 1, a), mincount(a.at(0), 0, a));
    }
    else
    {
        count = min(mincount(-1, 1, a), mincount(1, 1, a));
    }
    cout << count << endl;
}