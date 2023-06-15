// ############################ Template available in: https://propi.dev/cp  ############################ //
#pragma GCC optimize("-O3","-funroll-all-loops","-ffast-math")
#include <bits/stdc++.h>
//Debug methods
#define _(x) {cout << #x << " = " << x << endl;} //Print with endl
#define __(x) {cout << #x << " = " << x << " | ";} //Print without endl
#define _vec(x) {cout << #x << " = "; for(int i : x){cout << i << " ";} cout << endl;} //Print entire vector
#define _pair(x) {cout << #x << " = | " << "1st: " << x.first << " | " << "2nd: " << x.second << endl;} //Print pair
#define dbgs(x) cerr << (#x) << " --> " << (x) << ' '
#define dbg(x) cerr << (#x) << " --> " << (x) << endl
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
#define f(i,n) for(int i=0;i<n;i++)
#define rf(i,n) for(int i=n;i>=0;i--)
#define F(i,a,b) for(int i=a;i<b;i++)
#define RF(i,a,b) for(int i=a;i>=b;i--)
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define RFOR(it,c) for ( __typeof((c).rbegin()) it=(c).rbegin(); it!=(c).rend(); it++ )
#define all(c) c.begin(), c.end()
//IO Optimization
#define SpeedUP ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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
// ###################################################################################################### //

#define args p,q,r,s,t,u
#define fargs int p, int q, int r, int s, int t, int u

double equation(double x, fargs){
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + (double) t*x*x + u;
}

void plotInterval(double min, double max, double stepValue, fargs){
	cout << "== Ploting ==" << endl;
	for(double i=min; i<max; i+=stepValue){
		cout << equation(i,args) << " | ";
	}
	cout << endl << "== End of Plot ==" << endl;
}

int main(){
	// SpeedUP;
	string line;
	while(getline(cin,line)){
		istringstream iss(line);
		int args; iss >> p >> q >> r >> s >> t >> u;
		double lowerX = 0;
		double upperX = 1;
		double f_lowerX = equation(lowerX,args);
		double f_upperX = equation(upperX,args);
		if(f_lowerX * f_upperX > 0){
			cout << "No solution" << endl;
		} else{
			f(i,20){
				f_lowerX = equation(lowerX,args);
				f_upperX = equation(upperX,args);
				double middle = (lowerX + upperX)/2.0;
				if(abs(f_lowerX) < abs(f_upperX)){ // 0 is near lowerX
					upperX = middle;
				}else{
					lowerX = middle;
				}
			}
			if(abs(f_lowerX) < abs(f_upperX)){
				cout << lowerX << endl;
			}else{
				cout << upperX << endl;
			}
		}
		cout << endl;
	}
}
