#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &p : A)
        cin >> p;

    int odd = 0, even = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A.at(i) % 2 == 0)
        {
            even++;
            if (even == 2)
            {
                A.push_back(0);
                even = 0;
            }
        }
        else
        {
            odd++;
            if (odd == 2)
            {
                A.push_back(0);
                odd = 0;
            }
        }
    }
    if (odd + even == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}