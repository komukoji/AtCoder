#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        int res = i + 1;
        int sum = 0;
        while (res > 0)
        {
            sum += res % 10;
            res /= 10;
        }
        if (sum >= A && sum <= B)
            count += i + 1;
    }
    cout << count << endl;
}