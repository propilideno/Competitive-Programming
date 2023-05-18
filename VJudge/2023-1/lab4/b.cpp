#include <bits/stdc++.h>

using namespace std;

int main(){
    map<string,string> op;
    // Equivallent op in minHeap
    op = {{"insert", "push"},
         {"getMin", "top"},
         {"removeMin","pop"}};

    int n; cin >> n;
    string operation;
    int value;
    
    priority_queue<int, vector<int>> pq;
    while(n--){
        cin >> operation;
        if(op[operation] != "pop"){
            cin >> value;
        }
        cout << "Your choice: " << op[operation] << endl;
    }
} 
