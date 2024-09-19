#include <bits/stdc++.h>
using namespace std;

vector<int> color(100000,-1);
//vector<int> dist(100000,-1);

void dfs(vector<vector<pair<int,int>>> &tree, int i,int c){
    color.at(i)=c;
    for(auto next:tree.at(i)){
        if(color.at(next.first)!=-1)continue;
        if(next.second%2!=0){
            dfs(tree, next.first, 1-c);
        }
        else dfs(tree, next.first, c);
    }
}

int main(){
    int N;
    cin >> N;
    vector<vector<pair<int, int>>> tree(N,vector<pair<int,int>>(0));
    for(int i=0;i<N-1;i++){
        int u,v,w;
        cin >> u >> v >> w;
        u--;
        v--;
        tree.at(u).push_back(make_pair(v,w));
        tree.at(v).push_back(make_pair(u,w));
    }

    for(int i=0;i<N;i++){
        if(color.at(i)!=-1)continue;
        dfs(tree,i,0);
    }
    for(int i=0;i<N;i++){
        cout << color.at(i) << endl;
    }
}