#include <bits/stdc++.h>

using namespace std;

class SegTree {
public:
  SegTree(const vector<int> &arr) {
    n = arr.size();
    tree.resize(n * 4);
    build(1, 0, n - 1, arr);
  }

  int query(int l, int r) { return query(1, 0, n - 1, l, r); }

  void update(int i, int val) { update(1, 0, n - 1, i, val); }

private:
  vector<int> tree;
  int n;

  // função para construir a SegTree recursivamente
  void build(int v, int tl, int tr, const vector<int> &arr) {
    if (tl == tr) {
      tree[v] = arr[tl];
    } else {
      int tm = (tl + tr) / 2;
      build(v * 2, tl, tm, arr);
      build(v * 2 + 1, tm + 1, tr, arr);
      tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
  }

  // função para realizar uma consulta na SegTree recursivamente
  int query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
      return 0;
    }
    if (l == tl && r == tr) {
      return tree[v];
    }
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) +
           query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
  }

  // função para atualizar um valor na SegTree recursivamente
  void update(int v, int tl, int tr, int i, int val) {
    if (tl == tr) {
      tree[v] = val;
    } else {
      int tm = (tl + tr) / 2;
      if (i <= tm) {
        update(v * 2, tl, tm, i, val);
      } else {
        update(v * 2 + 1, tm + 1, tr, i, val);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  vector<int> pot;
  int n;
  int temp;
  string op; // String porque pode ser "END"
  int arg1, arg2;
  int i = 1;
  while (cin >> n && n != 0) {
    if (i != 1) {
      cout << endl;
    }
    cout << "Case " << i << ":" << endl;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      pot.push_back(temp);
    }
    SegTree T(pot); // Cria a Segment Tree
    while (cin >> op && op != "END") {
      cin >> arg1 >> arg2;
      if (op == "M") {
        cout << T.query(arg1 - 1, arg2 - 1)
             << endl; // arg1 e arg2 são numeros dos potenciometros.
      } else {        // op == "S"
        T.update(arg1 - 1,
                 arg2); // Arg1 é o potenciômetro e arg2 é a nova resistencia.
      }
    }
    i++;         // Proximo caso
    pot.clear(); // Limpa o array
  }
  return 0;
}
