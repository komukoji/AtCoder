#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> robot(N);
    for (int i = 0; i < N;i++){
        int X, L;
        cin >> X >> L;
        robot.at(i).first = X + L;
        robot.at(i).second = X - L;
    }
    sort(robot.begin(), robot.end());
    int ans = 0,t=INT_MIN;
    for (int i = 0; i < N;i++){
        if(t<=robot.at(i).second){
            ans++;
            t = robot.at(i).first;
        }
    }
    cout << ans;
}