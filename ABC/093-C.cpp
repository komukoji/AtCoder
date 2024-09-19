#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    int count = 0;
    if (A % 2 != B % 2 || B % 2 != C % 2 || C % 2 != A % 2)
    {
        count++;
        if (A % 2 == B % 2)
        {
            A++;
            B++;
        }
        else if (B % 2 == C % 2)
        {
            B++;
            C++;
        }
        else if (C % 2 == A % 2)
        {
            C++;
            A++;
        }
    }

    int rem = max(max(A, B), C);
    count += (rem - A) / 2 + (rem - B) / 2 + (rem - C) / 2;
    cout << count << endl;
}