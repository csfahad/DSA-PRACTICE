// Find the duplicate in an array of N+1 integers

// PROBLEM LINK:
// LEETCODE : https://leetcode.com/problems/find-the-duplicate-number/description/
// CODE STUDIO : https://www.codingninjas.com/studio/problems/1112602



// BRUTEFORCE APPROACH : USING SORTING

// Approach: Sort the array. After that, if there is any duplicate number they will be adjacent.
// So we simply have to check if arr[i]==arr[i+1] and if it is true,arr[i] is the duplicate number.

// Time Complexity:O(Nlogn + N)
// Reason: NlogN for sorting the array and O(N) for traversing through the array and checking 
// if adjacent elements are equal or not. But this will distort the array.

// Space Complexity:O(1)


#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector < int > & arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      return arr[i];
    }
  }
}

int main() {
  vector < int > arr;
  arr = {1,3,4,2,2};
  cout << "The duplicate element is " << findDuplicate(arr) << endl;
}



// BETTER SOLUTION : USING FREQUENCY ARRAY

// Approach: Take a frequency array of size N+1 and initialize it to 0. 
// Now traverse through the array and if the frequency of the element is 0 increase it by 1, 
// else if the frequency is not 0 then that element is the required answer.

// Time Complexity: O(N), as we are traversing through the array only once.
// Space Complexity: O(N), as we are using extra space for frequency array.


#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector < int > & arr) {
  int n = arr.size();
  int freq[n + 1] = {
    0
  };
  for (int i = 0; i < n; i++) {
    if (freq[arr[i]] == 0) {
      freq[arr[i]] += 1;
    } else {
      return arr[i];
    }
  }
  return 0;
}

int main() {
  vector < int > arr;
  arr = {1,3,4,2,3};
  cout << "The duplicate element is " << findDuplicate(arr) << endl;
}



// OPTIMAL APPROACH : LINKEDLIST CYCLE METHOD

// Time complexity: O(N). Since we traversed through the array only once.
// Space complexity: O(1).


#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector < int > & nums) {
  int slow = nums[0];
  int fast = nums[0];
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  fast = nums[0];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
}

int main() {
  vector < int > arr;
  arr = {1,3,4,2,3};
  cout << "The duplicate element is " << findDuplicate(arr) << endl;
}
