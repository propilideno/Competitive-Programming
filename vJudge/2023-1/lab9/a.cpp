/* ########################## Template available in: https://propi.dev/cp  ########################## */
// #pragma GCC optimize("-O3","-funroll-all-loops","-ffast-math") //Uncomment for a faster runtime
#include <bits/stdc++.h>
//Debug methods
#define _(x) {cout << #x << " = " << x << endl;} //Print with endl
#define __(x) {cout << #x << " = " << x << " | ";} //Print without endl
#define _vec(x) {cout << #x << " = "; for(int i : x){cout << i << " ";} cout << endl;} //Print entire vector
#define _pair(x) {cout << #x << " = | " << "1st: " << x.first << " | " << "2nd: " << x.second << endl;} //Print pair
#define __time__ { auto duration = chrono::duration<double>( \
std::chrono::high_resolution_clock::now() - beg);\
cout<<"Time: "<<duration.count()<<endl;}
//Constants
const auto beg = std::chrono::high_resolution_clock::now(); //Begining of the program
const double PI = acos(-1); //PI
const double E = 1e-8; //Small Number
const int INF_P = 0x3f3f3f3f; // Maximum positive integer that don't cause overflow when doubled
const int INF_N = 0xcfcfcfcf; // Minimum negative integer that don't cause underflow when doubled
const int MOD = 1e9+7; // Util with mod operations (prime number)
//Shortened Methods
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define sz(x) ((int)(x).size())
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
#define F(i,a,b) for(int i=a;i<b;i++)
#define RF(i,a,b) for(int i=a;i>=b;i--)
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define RFOR(it,c) for ( __typeof((c).rbegin()) it=(c).rbegin(); it!=(c).rend(); it++ )
#define REP(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end();)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
//IO Optimization
#define __SpeedUP__ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// Custom Data Structs
struct Graph { // Call like: Graph G(n); G.addEdge(u,v);
    int n; vector<unordered_set<int>> adj; Graph(int n) : n(n) { adj.resize(n); }
    void addEdge(int u, int v) { adj[u].insert(v); adj[v].insert(u); }
	void addNeighborEdge(int v, vi& visited){
		for(int i=1;i<=1000; i*=10){
			int left = v-i; int right = v+i;
			if((left < v) && valid(left,visited)) addEdge(v,left);
			if((right > v) && valid(right,visited)) addEdge(v,right);
		}
	}
	bool onLimit(int v){
		return (v >= 0 && v <= 9999);
	}
	bool valid(int v, vi& visited){
		return (onLimit(v) && visited[v] == INF_P);
	}
};

// HEADERS
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>; //Min Heap
template <template<typename...> class Container, typename T> // DFS: dbfs<stack,int>(G,v,visited)
void dbfs(Graph& G, int v, int out,vector<int>& visited);	 // BFS: dbfs<queue,int>(G,v,visited)
/* ################################################################################################## */

int readNumber(){
	int result = 0;
	for(int i=1000;i>=1;i/=10){
		int digit; cin >> digit;
		result += digit * i;
	}
	return result;
}

int main(){
	// __SpeedUP__ //Uncomment for a faster runtime
	int n=10000; Graph G(n);
	int t; cin >> t;
	while(t--){
		vector<int> visited(n,INF_P);
		int v = readNumber(), out = readNumber();
		int u; cin >> u;
		while(u--){
			visited[readNumber()] = 0;
		}
		if(visited[v] == 0) cout << -1 << endl;
		else if(v == out) cout << 0 << endl;
		else dbfs<queue,int>(G,out,v,visited);
	}
	
	// __time__ //Uncomment for show runtime
}

/* ################################################################################################## */

template <template<typename...> class Container, typename T>
void dbfs(Graph& G, int v, int out, vector<int>& visited) {
    Container<T> arr; arr.push(v); visited[v] = 0;
    while (!arr.empty() && v != out) {
		if constexpr(is_same<Container<T>, stack<typename Container<T>::value_type>>::value) {
			v = arr.top(); // Use top if using std::stack
		} else { v = arr.front(); } arr.pop(); // front if std::queue
		
		G.addNeighborEdge(v, visited);

        for (int w : G.adj[v]) {
            if (visited[w] == INF_P) {
                arr.push(w);
				visited[w] = visited[v] + 1;
            }
        }
    }
	cout << (v == out ? visited[v]+1 : -1) << endl;
}

/* ########################## Template available in: https://propi.dev/cp  ########################## */
