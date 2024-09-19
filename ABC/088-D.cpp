#include <bits/stdc++.h>
using namespace std;

int H,W;
vector<string> s;
vector<vector<int>> d;
vector<int> dx = {1,0,-1,0},dy = {0,1,0,-1};

int bfs(){
    queue<pair<int, int>> que;
    que.push(make_pair(0,0));
    d.assign(H,vector<int> (W,-1));
    d.at(0).at(0)=0;

    while(que.size()){
        pair<int,int> p=que.front();
        que.pop();
        if(p==make_pair(H-1,W-1))break;

        for(int i=0;i<4;i++){
            int nx=p.first+dx.at(i),ny=p.second+dy.at(i);
            if(nx<0||nx>=H||ny<0||ny>=W||s.at(nx).at(ny)=='#'||d.at(nx).at(ny)!=-1)continue;

            que.push(make_pair(nx,ny));
            d.at(nx).at(ny)=d.at(p.first).at(p.second)+1;
        }
    }
    return d.at(H-1).at(W-1);
}

int main(){
    cin >> H >> W;
    s.resize(H);
    for(string &p:s)cin >> p;

    int b=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(s.at(i).at(j)=='#')b++;
        }
    }
    int t=bfs();
    if(t==-1)cout << -1 << endl;
    else cout << (H*W-bfs()-1)-b << endl;
}