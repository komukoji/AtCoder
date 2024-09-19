#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> button(N);
    for (int i = 0; i < button.size(); i++)
    {
        cin >> button.at(i);
    }
    int i = 0, cur = 1;
    while (cur != 2)
    {
        if (i > N - 1)
        {
            i = -1;
            break;
        }
        cur = button.at(cur - 1);
        i++;
    }
    cout << i << endl;
}