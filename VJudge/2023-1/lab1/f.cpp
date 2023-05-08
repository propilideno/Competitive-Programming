#include <iostream>
using namespace std;
int main(){
    int n;
    float aux=0, feelings=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> aux;
        feelings += aux;
    }
    aux = feelings/n;
    if(aux > 0){ cout << ":)" << endl;}
    else if(aux == 0){ cout << ":|" << endl;}
    else{cout << ":(" << endl;}
}