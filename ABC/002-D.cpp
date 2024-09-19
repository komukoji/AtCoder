#include <bits/stdc++.h>
using namespace std;

void maxparty(int &ans, int i, vector<int> menber, int &N, vector<vector<int>> &acqua)
{ // i番目の議員を派閥に入れるかで場合分け
    if (i == N)
    {
        ans = max(ans, (int)menber.size());
        return;
    }
    bool allacq = true;// i番目の議員は現在のメンバー全員と知り合いか
    for (int j = 0; j < menber.size(); j++)
    {
        bool friends = false; // j番目のメンバーはi番目の議員の知り合いか
        for (int k = 0; k < acqua.at(menber.at(j)).size(); k++)
        {
            if (acqua.at(menber.at(j)).at(k) == i)
            {
                friends = true;
            }
        }
        if (!friends)
            allacq = false;
    }
    if (allacq)//全員と知り合いならメンバーに追加して次の議員調査
    {
        menber.push_back(i);
        maxparty(ans, i + 1, menber, N, acqua);
        menber.pop_back();
        // i番目の議員をメンバーに追加しない場合も調査
        maxparty(ans, i + 1, menber, N, acqua);
    }
    else{//全員と知り合いじゃないならi番目の議員はお祈りして次の議員調査
        // i番目の議員をメンバーに追加しない場合も調査
        maxparty(ans, i + 1, menber, N, acqua);
    }
    // i番目の議員をメンバー一号にして新しい党を設立
    menber = {i};
    maxparty(ans, i + 1, menber, N, acqua);
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> acqua(N, vector<int>(0));
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        acqua.at(x - 1).push_back(y - 1);
        acqua.at(y - 1).push_back(x - 1);
    }
    int ans = 0;
    vector<int> menber = {};
    maxparty(ans, 0, menber, N, acqua);
    cout << ans << endl;
}
