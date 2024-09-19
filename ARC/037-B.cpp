#include <bits/stdc++.h>
using namespace std;

bool tree(int k, set<int> &found, vector<vector<int>> &graph, int pretree)
{
    found.insert(k);

    bool maketree = true;
    for (int i = 0; i < graph.at(k).size(); i++)
    {
        if (graph.at(k).at(i) == pretree)
            continue;

        if (found.count(graph.at(k).at(i)))
        {
            return false;
        }
        maketree = maketree && tree(graph.at(k).at(i), found, graph, k);
    }
    return maketree;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(0));
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        graph.at(u - 1).push_back(v - 1);
        graph.at(v - 1).push_back(u - 1);
    }

    set<int> found;
    int n = 0;
    for (int i = 0; i < N; i++)
    {
        if (!found.count(i))
        {
            if (tree(i, found, graph, -1))
                n++;
        }
    }

    cout << n << endl;
}
