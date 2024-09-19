#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> vec(N - 1);//1~N-1まで
    for (int i = 0; i < N - 1; i++)
    {
        vec.at(i) = i + 1;
    }
    vector<vector<int>> graph(N, vector<int>(0));
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph.at(a - 1).push_back(b - 1);
        graph.at(b - 1).push_back(a - 1);
    }

    int count = 0;
    do
    {
        bool path = true;

        bool possible0 = false;
        for (int i = 0; i < graph.at(0).size(); i++)
        {
            if (graph.at(0).at(i) == vec.at(0))
                possible0 = true;
        }
        if (!possible0)
            path = false;

        for (int i = 0; i < vec.size() - 1; i++)
        {
            bool possible = false;
            for (int j = 0; j < graph.at(vec.at(i)).size(); j++)
            {
                if (graph.at(vec.at(i)).at(j) == vec.at(i + 1))
                {
                    possible = true;
                }
            }
            if (!possible)
                path = false;
        }
        if (path)
            count++;
    } while (next_permutation(vec.begin(), vec.end()));
    cout << count << endl;
}
