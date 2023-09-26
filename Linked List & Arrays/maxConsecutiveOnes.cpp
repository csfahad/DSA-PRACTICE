// Count Maximum Consecutive One’s in the array

// PROBLEM LINKS:
// LEETCODE: https://leetcode.com/problems/max-consecutive-ones/
// CODE STUDIO: https://www.codingninjas.com/studio/problems/892994


// Approach:  We maintain a variable count that keeps a track of the number of consecutive 1’s while traversing the array. 
// The other variable max_count maintains the maximum number of 1’s, in other words, it maintains the answer.


// Time Complexity: O(N) since the solution involves only a single pass.
// Space Complexity: O(1) because no extra space is used.



#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int findMaxConsecutiveOnes(vector <int> & nums) {
      int cnt = 0;
      int maxi = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
          cnt++;
        } else {
          cnt = 0;
        }

        maxi = max(maxi, cnt);
      }
      return maxi;
    }
};

int main() {
  vector < int > nums = { 1, 1, 0, 1, 1, 1 };
  Solution obj;
  int ans = obj.findMaxConsecutiveOnes(nums);
  cout << "The maximum  consecutive 1's are " << ans;
  return 0;
}
