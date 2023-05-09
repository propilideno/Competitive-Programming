#include <iostream>
using namespace std;

int main(){
    int t,a,b,c;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> a >> b >> c;
        cout << "Case " << i+1 << ": ";
        if((a > b && a < c) || (a < b && a > c)){cout << a;}
        else if((b > a && b < c) || (b < a && b > c)){cout << b;}
        else{cout << c;}
        cout << endl;
    }
}