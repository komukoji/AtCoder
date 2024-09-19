#include <iostream>
#include <vector>
using namespace std;
vector<int> coin;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> coin(m);
    for(int &p:coin){
        cin >> p;
    }

    vector<int> minpay(n + 1);//金額に対する最小の支払い方
    minpay.at(0) = 0;
    minpay.at(1) = 1;
    for (int i = 2; i <= n;i++){
        int pay = n;
        for (size_t j = 0; j < m; j++)
        {
            if(coin.at(j)<=i){
                int tmp = minpay.at(i - coin.at(j)) + 1;
                pay = min(pay, tmp);
            }
        }
        minpay.at(i) = pay;
    }
    cout << minpay.at(n) << endl;
}
