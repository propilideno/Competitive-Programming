#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        set<int> seen;
        int maxSeen = k;

        while (!seen.count(k)){
            seen.insert(k);
            k = stoi(to_string((long long)k * k).substr(0, n));
            if (k > maxSeen){
                maxSeen = k;
            }
        }

        cout << maxSeen << endl;
    }
}