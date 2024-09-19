#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> H(N);
    for (int &p : H)
    {
        cin >> p;
    }

    long long T = 0;
    for (int p : H)
    {
        long long carry = T % 3;
        if (carry == 1 && p > 1)
        {
            T += 2;
            p -= 4;
        }
        else if (carry == 1 && p == 1)
        {
            T += 1;
            continue;
        }
        if (carry == 2 && p > 1)
        {
            T += 1;
            p -= 3;
        }
        else if (carry == 2 && p == 1)
        {
            T += 1;
            continue;
        }

        int quo = p / 5;
        int rem = p % 5;
        T += 3 * quo;
        if (rem == 1)
        {
            T += 1;
        }
        else if (rem == 2)
        {
            T += 2;
        }
        else if (rem >= 3)
        {
            T += 3;
        }
    }
    cout << T << endl;
}
