#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, log = 40;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int Ai;
        cin >> Ai;
        int count = 0;
        while (true)
        {
            if (Ai % 2 == 0)
            {
                Ai /= 2;
                count++;
            }
            else
            {
                break;
            }
        }
        if (log > count)
        {
            log = count;
        }
    }
    cout << log << endl;
}