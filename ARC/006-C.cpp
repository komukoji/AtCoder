#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> w(N);
    for (int &p : w)
    {
        cin >> p;
    }
    vector<vector<int>> Graph(0);
    Graph.push_back(vector<int>(1, w.at(0)));
    for (int i = 1; i < N; i++)
    {
        int s = w.at(i);
        bool pile = false;
        for (int j = 0; j < Graph.size(); j++)
        {
            if (Graph.at(j).at(Graph.at(j).size() - 1) >= s)
            {
                Graph.at(j).push_back(s);
                pile = true;
                break;
            }
        }
        if (!pile)
        {
            Graph.push_back(vector<int>(1, s));
        }
    }
    cout << Graph.size() << endl;
}