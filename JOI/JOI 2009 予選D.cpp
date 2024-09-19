#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<string> card(n);
    for (int i = 0; i < n; i++)
    {
        cin >> card.at(i);
    }
    set<string> number;
    sort(card.begin(), card.end());
    do
    {
        string newcard = "";
        for (int i = 0; i < k; i++)
            newcard += card.at(i);
        number.insert(newcard);
    } while (next_permutation(card.begin(), card.end()));
    cout << number.size() << endl;
}