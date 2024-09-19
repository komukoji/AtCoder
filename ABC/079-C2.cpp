#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;

    for (int i = 0; i < (1 << 3); i++)
    {
        int sum = S.at(0) - '0';

        bool possible = false;

        bitset<3> plus(i);

        for (int j = 0; j < 3; j++)
        {
            if (plus.test(j))
            {
                sum += S.at(j + 1)-'0';
            }
            else
            {
                sum -= S.at(j + 1)-'0';
            }

            if (sum == 7)
            {
                possible = true;
                break;
            }
        }

        if (possible)
        {
            cout << S.at(0);
            for (int j = 0; j < 3; j++)
            {
                if (plus.test(j))
                {
                    cout << '+' << S.at(j + 1);
                }
                else
                {
                    cout << '-' << S.at(j + 1);
                }
            }
            cout << "=7" << endl;
            return 0;
        }
    }
}
