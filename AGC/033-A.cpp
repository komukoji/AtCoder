#include <bits/stdc++.h>
using namespace std;

int H,W;
vector<string> A;
vector<vector<int>> d;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};



int bfs(){
    d.assign(H,vector<int>(W,-1));
    queue<pair<int,int>> que;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(A.at(i).at(j)=='#'){
                d.at(i).at(j)=0;
                que.push(make_pair(i,j));
            }
        }
    }
    while(que.size()){
        pair<int,int> p=que.front();
        que.pop();
        
        A.at(p.first).at(p.second)='#';
        for(int i=0;i<4;i++){
            int nx=p.first+dx.at(i),ny=p.second+dy.at(i);
            if(nx<0||nx>=H||ny<0||ny>=W||A.at(nx).at(ny)=='#'||d.at(nx).at(ny)!=-1)continue;
            que.push(make_pair(nx,ny));
            d.at(nx).at(ny)=d.at(p.first).at(p.second)+1;
        }
    }
    int n=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            n=max(n,d.at(i).at(j));
        }
    }
    return n;
}

int main(){
    cin >> H >> W;
    A.resize(H);
    for(string &p:A)cin >> p;

    cout << bfs() << endl;
}