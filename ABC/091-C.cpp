#include <bits/stdc++.h>
using namespace std;
/*
方法は二つ
1.青をxの小さい方から見ていって、マッチング可能な中でyが最も高いものとマッチ
マッチングを進めるにつれマッチングできる赤のxの範囲は広まるが、yはマッチングしようとしているyの値による
→一番yの値を高いものを選んでおくのが最善
2.赤をxの高い方から見ていって、マッチング可能な中でyが最も低いものとマッチ
マッチングを進めるにつれマッチングできる青のxの範囲は広まるが、yはマッチングしようとしているyの値による
→一番yの値を低いものを選んでおくのが最善

赤をxの低い方から見ていって、マッチング可能な中でxが最も低いものとマッチするように選ぶと、y座標が高い青が消費され、y座標高めな赤のマッチング相手がいなくなる可能性がある。マッチング可能な中でyが最も低いものとマッチするように選ぶと、今度はx座標が高い青が消費され、x座標高めな赤のマッチング相手がいなくなる可能性がある。
*/
int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> red(N), blue(N);
    for (auto &p : red)
    {
        cin >> p.first >> p.second;
    }
    for (auto &p : blue)
    {
        cin >> p.first >> p.second;
    }
    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());
    vector<bool> used(N,false);//赤色使用済み
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int maxy=-1, maxid=-1;
        for (int j = 0; j < N;j++){
            if(used[j]){
                continue;
            }
            if(red.at(j).first>=blue.at(i).first){
                continue;
            }
            if(red.at(j).second>=blue.at(i).second){
                continue;
            }
            if(maxy<red.at(j).second){
                maxid = j;
                maxy = red.at(j).second;
            }
        }
        if(maxid==-1){
            continue;
        }
        ans++;
        used[maxid] = true;
    }
    cout << ans << endl;
}