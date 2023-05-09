#include <bits/stdc++.h>

using namespace std;

int main() {
  unsigned int n, a, b;
  while (cin >> n && n != 0) {
    unordered_map<unsigned int, unsigned short> soldier;
    long long x = 0;
    unsigned int survivors = n;
    cin >> a >> b;
    for (unsigned int steps = 0;
         survivors > 0 && soldier[x] != 3 && steps <= 1e6; steps++) {
      soldier[x]++;
      if (soldier[x] == 2) {
        survivors--; // Eliminated
      }
      // x=(a*x*x +b%n)%n; //Next Soldier
      x = ((a % n * x % n * x) + b) % n; // Mod Properties
    }
    cout << survivors << endl;
  }
}
