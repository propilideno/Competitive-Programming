#include <iostream>
using namespace std;

int main(){
    int k,divisa[2],coord[2];
    while(cin >> k && k != 0){
        cin >> divisa[0] >> divisa[1];
        for(int i=0;i<k;i++){
            cin >> coord[0] >> coord[1];
            if(coord[0] == divisa[0] || coord[1] == divisa[1]){cout << "divisa";}
            else if(coord[0] >= divisa[0] && coord[1] >= divisa[1]){cout << "NE";}
            else if(coord[0] <= divisa[0] && coord[1] >= divisa[1]){cout << "NO";}
            else if(coord[0] <= divisa[0] && coord[1] <= divisa[1]){cout << "SO";}
            else if(coord[0] >= divisa[0] && coord[1] <= divisa[1]){cout << "SE";}
            cout << endl;
        }
    }
}