#include <bits/stdc++.h>
using namespace std;

vector<int> color(100000,-1);
int64_t B=0LL,W=0LL;

bool dfs(vector<vector<int>> &graph,int i,int cur){
    color.at(i)=cur;
    if(cur==0)W++;
    else B++;
    for(int v:graph.at(i)){
        if(color.at(v)!=-1){
            if(color.at(v)==cur)return false;
            continue;
        }
        if(!dfs(graph,v,1-cur))return false;
    }
    return true;
}

int main(){
    int64_t N,M;
    cin >> N >> M;
    vector<vector<int>> graph(N,vector<int> (0));
    for(int i=0;i<M;i++){
        int A,B;
        cin >> A >> B;
        A--;
        B--;
        graph.at(A).push_back(B);
        graph.at(B).push_back(A);
    }

    bool is_bipartite=true;
    for(int i=0;i<N;i++){
        if(color.at(i)!=-1)continue;
        if(!dfs(graph,i,0))is_bipartite=false;
    }

    if(is_bipartite)cout << B*W-M << endl;
    else cout << N*(N-1)/2-M << endl;
}