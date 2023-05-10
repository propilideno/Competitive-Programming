#include <bits/stdc++.h>

using namespace std;

void buildRec(int *T, int *A, int node, int start, int end) {
  if (start == end) {
    // # Folha representa um elemento único
    T[node] = A[start];
  } else {
    int mid = (start + end) / 2;
    // # Chamada recursiva para filho à esquerda
    buildRec(T, A, 2 * node, start, mid);
    // # Chamada recursiva para filho à direita
    buildRec(T, A, 2 * node + 1, mid + 1, end);
    // # Nó interno tem a SOMA dos dois filhos
    T[node] = T[2 * node] + T[2 * node + 1]; // # <======= IMPORTANTE
  }
}
void build(int *T, int *A, int n) {
  buildRec(T, A, 1, 0,
           n - 1); // # A raíz tem nó 1 e representa o segmento A[0, ..., n-1]
}

int queryRec(int *T, int node, int start, int end, int l, int r) {
  if (r < start or end < l) {
    // # [start, end] está fora de [l, r] -- não há interseção
    return 0; // # <======= IMPORTANTE
  }
  if (l <= start and end <= r) {
    // # [start, end] está contido em [l, r]
    return T[node];
  }
  // # [start, end] e [l, r] têm interseção
  int mid = (start + end) / 2;
  int p1 = queryRec(T, 2 * node, start, mid, l, r);
  int p2 = queryRec(T, 2 * node + 1, mid + 1, end, l, r);
  return (p1 + p2); // # <======= IMPORTANTE
}
int query(int *T, int n, int l, int r) { // #Soma(A[l, ..., r])
  return queryRec(T, 1, 0, n - 1, l, r);
}

void updateRec(int *T, int *A, int node, int start, int end, int idx, int val) {
  if (start == end) {
    // # Nó folha, atualiza A e T
    A[idx] = val;  // Modificado
    T[node] = val; // Modificado
  } else {
    int mid = (start + end) / 2;
    if (start <= idx and idx <= mid) {
      // # idx está no filho à esquerda
      updateRec(T, A, 2 * node, start, mid, idx, val);
    } else {
      // # idx está no filho à direita
      updateRec(T, A, 2 * node + 1, mid + 1, end, idx, val);
    }
    // # Faz atualização do nó pai
    T[node] = T[2 * node] + T[2 * node + 1]; // # <======= IMPORTANTE
  }
}
void update(int *T, int *A, int n, int idx, int val) { // # A[idx] = A[idx] +
                                                       // val
  updateRec(T, A, 1, 0, n - 1, idx, val);
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  int temp;
  string op; // String porque pode ser "END"
  int arg1, arg2;
  int i = 1;
  while (cin >> n && n != 0) {
    int pot[n];
    int T[4 * n];
    if (i != 1) {
      cout << endl;
    }
    for (int i = 0; i < n; i++) {
      cin >> pot[i];
    }
    build(T, pot, n); // Cria a Segment Tree
    cout << "Case " << i << ":" << endl;
    while (cin >> op && op != "END") {
      cin >> arg1 >> arg2;
      if (op == "M") {
        cout << query(T, n, arg1 - 1, arg2 - 1)
             << endl; // arg1 e arg2 são numeros dos potenciometros.
      } else {        // op == "S"
        update(T, pot, n, arg1 - 1,
               arg2); // Arg1 é o potenciômetro e arg2 é a nova resistencia.
      }
    }
    i++; // Proximo caso
  }
  return 0;
}
