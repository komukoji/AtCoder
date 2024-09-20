#include <bits/stdc++.h>
using namespace std;

int main() {
  int m;
  cin >> m;
  
  if (m < 100)
    cout << 0 << 0 << endl;
  
  if (m >= 100 && m < 1000)
    cout << 0 << m / 100 << endl;
  
  if (m >= 1000 && m <= 5000)
    cout << m / 100 << endl;
  
  if (m >= 6000 && m <= 30000)
    cout << m / 1000 + 50 << endl;
  
  if (m >= 35000 && m <= 70000)
    cout << (m / 1000 - 30) / 5 + 80 << endl;
  
  if (m > 70000)
    cout << 89 << endl;
}