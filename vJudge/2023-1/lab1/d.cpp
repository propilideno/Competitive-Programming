#include <iostream>
#include <map>

using namespace std;

int main(){
    unsigned int n,a,b;
    while(cin >> n && n != 0){
        map<unsigned int,unsigned short> sorted;
        long long x = 0;
        unsigned int alive = n;
        cin >> a >> b;
        for(unsigned int steps=0;alive > 0 && sorted[x] != 3 && steps <= 1e6;steps++){
            sorted[x] ++;
            if (sorted[x] == 2){
                alive--; //Eliminated
            }
            //x=(a*x*x +b)%n; //Next Soldier
            x = (((a%n)*(x*x%n)) + b)%n;
        }
        cout << alive << endl;
    }
}