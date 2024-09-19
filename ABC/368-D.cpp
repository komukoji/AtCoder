#include <bits/stdc++.h>
using namespace std;
//TODO
void dfs(int v, vector<bool> &v_checked, vector<vector<int>> &tree){
    v_checked;
}

int main(){
    int N, K;
    cin >> N >> K;
    vector<vector<int>> tree(N, vector<int>(0));

    for (int i = 0; i < N - 1;i++){
        int A, B;
        cin >> A >> B;
        tree.at(A - 1).push_back(B - 1);
        tree.at(B - 1).push_back(A - 1);
    }

    vector<bool> v_needed(N);
    for (int i = 0; i < K;i++)
    {
        int p;
        cin >> p;
        v_needed.at(p - 1) = true;
    }

    vector<bool> v_checked(N, false);
}
