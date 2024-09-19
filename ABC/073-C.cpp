#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    set<int> paper;
    for (int i = 0; i < N; i++)
    {
        int rem;
        cin >> rem;
        if (paper.count(rem))
            paper.erase(rem);
        else
            paper.insert(rem);
    }
    cout << paper.size() << endl;
}
