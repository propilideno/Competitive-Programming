#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> k(n);
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }
  sort(k.begin(), k.end()); // Ordena o array

  auto left = k.begin();           // Começa no começo
  auto middle = k.begin() + n / 2; // Iterador pro meio do array

  int numberOf_Clusters = 0;
  int numberOf_Alones = 0;
  if (n % 2) {
    numberOf_Alones++; // O do meio fica sozinho
    middle++;          // O meio passa a ser o próximo
  }
  for (auto right = middle; right <= k.end(); right++) {
    if (2 * (*left) <= *right) { // Pelo menos o dobro.
                                 // Quer dizer que o dobro vale.
      numberOf_Clusters++;
      left++;
    } else {
      numberOf_Alones++;
    }
  }

  cout << numberOf_Clusters + numberOf_Alones << endl;
}
