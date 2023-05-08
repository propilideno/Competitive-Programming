#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int boxes = ceil((float) n/k);
    cout << boxes << endl;
}