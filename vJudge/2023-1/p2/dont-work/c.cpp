/* ########################## Template available in: https://propi.dev/cp  ########################## */
#pragma GCC optimize("-O3","-funroll-all-loops","-ffast-math") //Uncomment for a faster runtime
#include <bits/stdc++.h>
//Debug methods
#define _(x) {cout << #x << " = " << x << endl;} //Print with endl
#define __(x) {cout << #x << " = " << x << " | ";} //Print without endl
#define _vec(x) {cout << #x << " = "; for(int i : x){cout << i << " ";} cout << endl;} //Print entire vector
#define _pair(x) {cout << #x << " = | " << "1st: " << x.first << " | " << "2nd: " << x.second << endl;} //Print pair
//Constants
const double PI = acos(-1); //PI
const double E = 1e-8; //Small Number
const int INF_N = (2 << 30); //Min_INT
const int INF_P = (INF_N+1)*(-1); //Max_INT
//Shortened Methods
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
//loops
#define f(i,n) for(int i=0;i<n;i++) //From 0 to n-1
#define rf(i,n) for(int i=n-1;i>=0;i--) //From n-1 to 0
#define F(i,a,b) for(int i=a;i<b;i++)
#define RF(i,a,b) for(int i=a;i>=b;i--)
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define RFOR(it,c) for ( __typeof((c).rbegin()) it=(c).rbegin(); it!=(c).rend(); it++ )
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
//IO Optimization
#define SpeedUP ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//Data Structures and Types
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
/* ################################################################################################## */

int traverse(vi stones, int d, int maxHop){
	int currentHop = 0;
	if(sz(stones) == 0){
		maxHop = d;
	} else{
		f(i,sz(stones)-1){
			currentHop = stones[i+1] - stones[i];
			if(currentHop > maxHop){ maxHop = currentHop; }
		}
		currentHop = d - stones[sz(stones)-1];
		if(currentHop > maxHop){ maxHop = currentHop; }
	}
	return maxHop;
}

int main(){
	SpeedUP; //Uncomment for a faster runtime
	string line;
	int t; cin >> t;
	int n, d;
	char stone;
	f(j,t){
		cin >> n >> d;
		vi lrPath, rlPath, s_stones;
		f(i,n){
			char temp, junk; int m;
			cin >> temp >> junk >> m; // Lê a entrada e descarta o hífen
			if(temp == 'B'){
				lrPath.pb(m); rlPath.pb(m); // Pedras B vão para os 2 caminhos
			}else{
				s_stones.pb(m);
			}
		}
		sort(all(lrPath));sort(rall(rlPath)); //Ordena os arrays
		f(i,sz(s_stones)){
			//Par -> Caminho LR | Impar -> Caminho RL
			(i%2 == 0) ? lrPath.pb(s_stones[i]) : rlPath.pb(s_stones[i]);
		}
		// Left to right
		int maxHop = traverse(lrPath, d, 0);
		// Right to left
		maxHop = traverse(rlPath, d, maxHop);
		cout << "Case " << j+1 << ": " << maxHop << endl;
	}
}
