#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

class Solution {
public:
  // FloydHarshall algorithm
  void findDuplicate(vector<int> &nums) {
    int slow = 0, fast = 0;
    while (1) {
      slow = nums[slow];
      fast = nums[nums[fast]];
      if (slow == fast) {
        slow = 0;
        break;
      }
    }
    while (1) {
      slow = nums[slow];
      fast = nums[fast];
      if (slow == fast) {
        cout << slow << std::endl;
        return;
      }
    }
  }
};

int main() {
  vector<int> t1{1, 3, 4, 2, 2};
  vector<int> t2{3, 1, 3, 4, 2};
  Solution sol;
  sol.findDuplicate(t1);
  sol.findDuplicate(t2);
}
