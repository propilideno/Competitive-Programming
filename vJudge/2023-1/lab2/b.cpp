#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, sum;
  bool corrupted = false;
  vector<short> corruptRow, corruptCol;
  while (cin >> n && n != 0) {
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      sum = 0;
      for (int j = 0; j < n; j++) {
        cin >> matrix[i][j];
        sum += matrix[i][j];
      }
      if ((sum & 1) == 1) {
        corruptRow.push_back(i);
      }
      if (corruptRow.size() > 1) {
        corrupted = true;
      }
    }
    if (corrupted == false) {
      for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
          sum += matrix[j][i];
        }
        if ((sum & 1) == 1) {
          corruptCol.push_back(i);
        }
      }
      if (corruptCol.size() > 1) {
        corrupted = true;
        break;
      }
      if (corruptRow.empty() && corruptCol.empty()) {
        cout << "OK" << endl;
      } else if (corrupted == true) {
        cout << "Corrupted" << endl;
      } else {
        cout << "Change bit (" << endl;
      }
    } else {
      cout << "Corrupted" << endl;
    }
  }
}
