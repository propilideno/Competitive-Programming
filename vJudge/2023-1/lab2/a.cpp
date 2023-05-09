#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n, a1, a2, currentValue;
    while(cin >> n && cin >> a1){
        bool isJolly = true;
        vector<bool> diffPresent(n-1, false);
        cin >> a2;
        currentValue = abs(a2 - a1);
        diffPresent[currentValue-1] = true;
        for(int i=0; i<n-2; i++){
            if(!isJolly) { continue; }
            a1 = a2;
            cin >> a2;
            currentValue = abs(a2 - a1);
            if(currentValue <= 0 || currentValue >= n || diffPresent[currentValue-1]){isJolly = false;}
            diffPresent[currentValue-1] = true;
        }
    cout << (isJolly ? "Jolly" : "Not jolly") << endl;
    }
}