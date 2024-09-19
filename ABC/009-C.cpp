#include <bits/stdc++.h>
using namespace std;

int N;
int diff(vector<int> &alphaS, vector<int> &alphaT, int j)//j+1文字目以降の文字の文字不一致個数計算
{
    int accord = 0;
    for (int i = 0; i < 26; i++)
    {
        accord += min(alphaS.at(i), alphaT.at(i));
    }
    return N - (j + 1) - accord;
}

int main()
{
    int K;
    string S;
    cin >> N >> K >> S;
    if (K == 0 || K == 1) // 文字を入れ替える時少なくとも二文字元の文字列と違う箇所ができる
    {
        cout << S << endl;
        return 0;
    }
    string T = "";             // 答えの文字列
    vector<int> alphaS(26, 0); // 元の文字列の(i番目以降の)アルファベット出現回数
    vector<int> alphaT(26, 0); // 新しく作る文字列の(i番目以降の)アルファベット出現回数
    for (size_t i = 0; i < N; i++)
    {
        alphaS.at(S.at(i) - 'a')++;
        alphaT.at(S.at(i) - 'a')++;
    }

    int d = 0;                     // ここまでの文字不一致個数
    for (size_t i = 0; i < N; i++) // 一文字ずつgreedyでTを決定
    {
        alphaS.at(S.at(i) - 'a')--; // Sのi+1番目以降の文字出現回数
        if (d == K)                 // 文字入れ替え個数がKになったらもう移動できない
        {
            T.push_back(S.at(i));
            continue;
        }
        for (size_t j = 0; j < 26; j++) // アルファベット順に探索
        {
            if (alphaT.at(j) == 0) // j番目のアルファベットがSの残りの文字出現回数で０なら飛ばす
            {
                continue;
            }
            if (S.at(i) - 'a' == j) // i文字目に入れたい文字がSのi文字目と同じなら並べ替えの回数を増やさなくて済む
            {
                T.push_back(S.at(i));
                alphaT.at(j)--;
                break;
            }

            alphaT.at(j)--;
            if (d + 1 + diff(alphaS, alphaT, i) <= K)//i文字目に入れたい文字がSのi文字目と違う時は必要文字入れ替え個数がK以下なら
            {
                d++;
                T.push_back((char)(j + 'a'));
                break;
            }
            alphaT.at(j)++;
        }
    }
    cout << T << endl;
}
