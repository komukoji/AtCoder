#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    int count = 0;
    for (int i = 0; i <= A; i++)
    {
        if (X - 500 * i >= 0)
        {
            int rem1;
            rem1 = X - 500 * i;
            for (int j = 0; j <= B; j++)
            {
                if (rem1 - 100 * j >= 0)
                {
                    int rem2;
                    rem2 = rem1 - 100 * j;
                    if (rem2 / 50 <= C)
                        count++;
                }
            }
        }
    }
    cout << count << endl;
}