/* ########################## Template available in: https://propi.dev/cp  ########################## */
#pragma GCC optimize("-O3","-funroll-all-loops","-ffast-math") //Uncomment for a faster runtime
#include <bits/stdc++.h>
//Debug methods
#define _(x) {cout << #x << " = " << x << endl;} //Print with endl
#define __(x) {cout << #x << " = " << x << " | ";} //Print without endl
#define _vec(x) {cout << #x << " = "; for(int i : x){cout << i << " ";} cout << endl;} //Print entire vector
#define _pair(x) {cout << #x << " = | " << "1st: " << x.first << " | " << "2nd: " << x.second << endl;} //Print pair
#define __time__ { auto duration = chrono::duration<double>( /* Show runtime */ \
std::chrono::high_resolution_clock::now() - beg); cout<<"Time: "<<duration.count()<<endl;}
#define __log__ { std::FILE* file = std::freopen("LOG.txt", "w", stdout); }
//Constants
const auto beg = std::chrono::high_resolution_clock::now(); //Begining of the program
const double PI = acos(-1); //PI
const double E = 1e-8; //Small Number (10^-8)
const int INF_P = 0x3f3f3f3f; //Max positive integer that don't cause overflow when doubled
const int INF_N = 0xcfcfcfcf; //Min negative integer that don't cause underflow when doubled
const int MOD = 1e9+7; //Mod operations (prime number)
//Shortened Methods
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
//Shortened Types
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair <ll, ll> pll;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::vector<std::pair<int, int> > vpii;
typedef std::map<int, int> mii;
typedef std::map<ll, ll> mll;
typedef std::pair<int, int> pii;
typedef std::pair<std::string, int> psi;
//loops
#define f(i,n) for(int i=0;i<n;i++) //From 0 to n-1
#define rf(i,n) for(int i=n-1;i>=0;i--) //From n-1 to 0
#define F(i,a,b) for(int i=a;i<b;i++) // From a to b-1
#define RF(i,a,b) for(int i=a;i>=b;i--) // From a to b-1
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define RFOR(it,c) for ( __typeof((c).rbegin()) it=(c).rbegin(); it!=(c).rend(); it++ )
#define REP(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end();)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define sz(x) ((int)(x).size())
#define ms(arr,val) memset(arr,val,sizeof(arr))
//IO Optimization
#define __SpeedUP__ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// Custom Data Structs
int VI_to_INT(vi digit);
vi INT_to_VI(int v);
struct Graph { // Call like: Graph G(n); G.addEdge(u,v);
    int n; vector<unordered_set<int>> adj;
	Graph(int size) : n(size) { adj.resize(size); }
    void addEdge(int u, int v) { adj[u].insert(v); adj[u].insert(v); }
	void removeEdge(int u, int v) { adj[u].erase(v); }
	void addNeighbors(int v, vector<int> visited){
		vi digits = INT_to_VI(v);
		f(i,4){
			vi left = digits, right = digits;
			left[i] --; right[i] ++;
			if(digits[i] == 0) left[i] = 9;
			else if(digits[i] == 9) right[i] = 0;
			int leftVal = VI_to_INT(left), rightVal = VI_to_INT(right);
			if(visited[leftVal] != -1) addEdge(v,leftVal);
			if(visited[rightVal] != -1) addEdge(v,rightVal);
		}
	}
};
// HEADERS
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>; //Min Heap
struct Graph; //Graph with adjacency list					 // vector <bool> visited(n,false);
template <template<typename...> class Container, typename T> // DFS: dbfs<stack,int>(G,v,visited)
int dbfs(Graph& G, int v, int out,vector<int>& visited);	 // BFS: dbfs<queue,int>(G,v,visited)

/* ################################################################################################## */

vi INT_to_VI(int v) {
	string temp = to_string(v);
	vi digits(4);
	if(sz(temp) < 4){
		int n = sz(temp);
		f(i,n){
			// cout << "Did it" << endl;
			digits[i] = 0;
		}for(int i=4-n, j=0; i<4; i++, j++){
			digits[i] = temp[j] - '0';
		}
	}
	else{
		f(i,4) digits[i] = temp[i] - '0';
	}
	return digits;
}


int VI_to_INT(vi digit){
	// _vec(digit)
	int value = digit[0] *1000 + digit[1] * 100 + digit[2]*10 + digit[3];
	// _(value)
	return value;
}

vi CIN_to_VI(){
	vi digit(4);
	f(i,4){ cin >> digit[i]; }
	return digit;
}

int readNumber(){
	vi digit = CIN_to_VI();
	// _vec(digit)
	return VI_to_INT(digit);
}

int main(){
	__SpeedUP__ //Uncomment for a faster runtime
	// __log__ //Uncomment for get cout into LOG.txt
	int t; cin >> t;
	int n = 10000;
	string trash;
	Graph G(n); vector<int> visited(n,INF_P);
	f(k,t){
		G.adj.clear();
		visited.assign(n,INF_P);
		int v = readNumber(); 
		int out = readNumber();
		int e; cin >> e; while(e--){
			int excluded = readNumber();
			visited[excluded] = -1; //Forbidden
		}
		getline(cin,trash); //Trash
		cout << dbfs<queue,int>(G,v,out,visited) << endl;
	}

	// __time__ //Uncomment for show runtime
}


/* ################################################################################################## */

template <template<typename...> class Container, typename T>
int dbfs(Graph& G, int v, int out, vector<int>& visited) {
    Container<T> arr; arr.push(v); visited[v] = 0;
	while (!arr.empty()) {
		if constexpr(is_same<Container<T>, stack<typename Container<T>::value_type>>::value) {
			v = arr.top(); // Use top if using std::stack
		} else { v = arr.front(); } arr.pop(); // front if std::queue

		if(v == out) return visited[v];
		G.addNeighbors(v, visited);

        for (int w : G.adj[v]) { // For each unvisited neighbor of v
            if (visited[w] == INF_P) {
                arr.push(w); visited[w] = visited[v] +1;
            }
        }
    } return -1;
}

/* ########################## Template available in: https://propi.dev/cp  ########################## */
