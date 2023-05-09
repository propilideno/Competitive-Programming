/*In:
3
10 20
20 10
10 10
*/

/*Out:
<
>
=
*/
#include <iostream>
using namespace std;
int main(){
    int t,a,b;
    cin >> t;
    if(t >= 15 || t < 0){return 1;}
    for(int i=0;i<t;i++){
        cin >> a;
        cin >> b;
        if(abs(a) >= 1000000001 || abs(b) >= 1000000001){return 1;}
        else if(a > b){
            cout << '>';
        }
        else if(a < b){
            cout << '<';
        }
        else{
            cout << '=';
        }
        cout << endl;
    }
}