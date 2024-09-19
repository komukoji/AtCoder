#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &p : A)
        cin >> p;

    int count = 0;
    bool plus = true;
    for (int i = 0; i < N - 1; i++)
    {
        if (A.at(i) == A.at(i + 1))
            continue;
        if (A.at(i) < A.at(i + 1))
        {
            plus = true;
            break;
        }
        else
        {
            plus = false;
            break;
        }
    }

    for (int i = 1; i < N; i++)
    {
        if (plus && A.at(i) < A.at(i - 1))
        {
            count++;
            for (int j = i; j < N - 1; j++)
            {
                if (A.at(j) == A.at(j + 1))
                    continue;
                if (A.at(j) < A.at(j + 1))
                {
                    plus = true;
                    break;
                }
                else
                {
                    plus = false;
                    break;
                }
            }
        }
        else if (!plus && A.at(i) > A.at(i - 1))
        {
            count++;
            for (int j = i; j < N - 1; j++)
            {
                if (A.at(j) == A.at(j + 1))
                    continue;
                if (A.at(j) < A.at(j + 1))
                {
                    plus = true;
                    break;
                }
                else
                {
                    plus = false;
                    break;
                }
            }
        }

        if (i == N - 1)
            count++;
    }
    if (N == 1)
        count = 1;
    cout << count << endl;
}
