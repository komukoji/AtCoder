#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int res = 0, FindID = 1;
    for (int i = 1; i <= N; i++)
    {
        int count = 0, n;
        n = i;
        while (n % 2 == 0)
        {
            n = n / 2;
            count++;
        }
        if (res < count)
        {
            res = count;
            FindID = i;
        }
    }
    cout << FindID << endl;
}