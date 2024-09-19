#include <bits/stdc++.h>
using namespace std;

int valuekinds(vector<int> &A)
{
    int count = 0;
    for (int p : A)
    {
        if (p > 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &p : A)
    {
        cin >> p;
    }
    sort(A.begin(), A.end(), greater<int>());
    int count = 0;
    while (valuekinds(A) > 1)
    {
        A.at(0)--;
        A.at(1)--;
        sort(A.begin(), A.end(), greater<int>());
        count++;
    }
    cout << count << endl;
}
