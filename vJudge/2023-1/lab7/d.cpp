#include <bits/stdc++.h>

#define DEBUG false
#define OJ_DEBUG

#define $(x) {if (DEBUG) {cout << __LINE__ << ": "; {x} cout << endl;}}
#define _(x) {cout << #x << " = " << x << " " << endl;}

const double E = 1e-8;
const double PI = acos(-1);

using namespace std;

class Solution{
public:
	Solution(){}
	void problem(vector<int>& nums){}
private:
	vector<int> nums;
};

int main(){
	ios::sync_with_stdio(false);
	string line;
	int maxSwap;
	cin >> line >> maxSwap;
	vector<int> nums;
	for(char c : line){
		nums.push_back(c - '0'); //Push char as integer
	}
	for(auto i = nums.begin() ; maxSwap >= 0  && i != nums.end()-1 ; i++){
		int maxRange = maxSwap > nums.size() ? nums.size() : maxSwap;
		auto leftMostMax = max_element(i,i+maxRange+1);
		int hops = distance(i,leftMostMax);
		if(hops > 0){
			while(leftMostMax != i){ // (Recursively swap)
				swap(*leftMostMax,*(leftMostMax-1));
				leftMostMax--;
			}
			maxSwap -= hops; 
		}
	}

	for(int i : nums){
		cout << i;
	}
	cout << endl;

}
