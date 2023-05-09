#include <iostream>
using namespace std;
int main(){
    int n,wLen; cin >> n;
    while(n--){
        std::string word; cin >> word;
        wLen = word.length();
        //cout << word.length() << endl;
        if(wLen <= 10){
            cout << word << endl;
        }
        else{
            cout << word.front() << wLen -2 << word.back() << endl;
        }
    }
}