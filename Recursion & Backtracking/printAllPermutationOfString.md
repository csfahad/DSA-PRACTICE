# Print All Permutations of a String/Array

## Problem links :

### [Leetcode](https://leetcode.com/problems/permutations/)

### [CodeStudio](https://www.codingninjas.com/studio/problems/758958)

## Approach 1 - Recursive

**Approach**: We have given the nums array, so we will declare an ans vector of vector that will store all the permutations also declare a data structure.

Declare a map and initialize it to zero and call the recursive function

**Base condition:**

When the data structure’s size is equal to n(size of nums array) then it is a permutation and stores that permutation in our ans, then returns it.

**Recursion:**

Run a for loop starting from 0 to nums.size() – 1. Check if the frequency of i is unmarked, if it is unmarked then it means it has not been picked and then we pick. And make sure it is marked as picked.

Call the recursion with the parameters to pick the other elements when we come back from the recursion make sure you throw that element out. And unmark that element in the map.

**Recursive Tree :**

![Recursive Tree](https://lh5.googleusercontent.com/_HggDGd3RQxtGztkBl-RiWG1-30xybzsuKdwkFHD72hYudulc9gpcujvsMYRp0Rh6jTN7J_m-kM2hL7uV6vjMTICcy3MzHQQcu1kHHVlQCu9emq8YfRj5gsNfwDFBuVNqd4Md68u)

### **Time Complexity:** N! x N

### **Space Complexity:** O(N)

**Code :**

```cpp

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void recurPermute(vector < int > & ds, vector < int > & nums, vector < vector < int >> & ans, int freq[]) {
      if (ds.size() == nums.size()) {
        ans.push_back(ds);
        return;
      }
      for (int i = 0; i < nums.size(); i++) {
        if (!freq[i]) {
          ds.push_back(nums[i]);
          freq[i] = 1;
          recurPermute(ds, nums, ans, freq);
          freq[i] = 0;
          ds.pop_back();
        }
      }
    }
  public:
    vector < vector < int >> permute(vector < int > & nums) {
      vector < vector < int >> ans;
      vector < int > ds;
      int freq[nums.size()];
      for (int i = 0; i < nums.size(); i++) freq[i] = 0;
      recurPermute(ds, nums, ans, freq);
      return ans;
    }
};

int main() {
  Solution obj;
  vector<int> v{1,2,3};
  vector < vector < int >> sum = obj.permute(v);
  cout << "All Permutations are " << endl;
  for (int i = 0; i < sum.size(); i++) {
    for (int j = 0; j < sum[i].size(); j++)
      cout << sum[i][j] << " ";
    cout << endl;
  }
}

```

## Approach 2 - Using Backtracking

We have given the nums array, so we will declare an ans vector of vector that will store all the permutations.

Call a recursive function that starts with zero, nums array, and ans vector.

Declare a map and initialize it to zero and call the recursive function

**Base condition:**

Whenever the index reaches the end take the nums array and put it in ans vector and return.

**Recursion:**

Go from index to n – 1 and swap once the swap has been done call recursion for the next state. After coming back from the recursion make sure you re-swap it because, for the next element, the swap will not take place.

**Recursive Tree:**

![Recursive Tree](https://lh4.googleusercontent.com/rT5kZ2p2oZJIoSa2DcjQ2NTyUUVGEeOCCDtcdvZi1lTyIjnXuAFaQ4tI7TxHqLqdR4Xig4ncX37p2SBmT5hfihQWGpiFL_foQl2kGwVnvz6VGlfHqS_bbc-8VGsJDeb0CfiC7aSN)

### **Time Complexity:** O(N! X N)

### **Space Complexity:** O(1)

**Code :**

```cpp

#include<bits/stdc++.h>

using namespace std;
class Solution {
  private:
    void recurPermute(int index, vector < int > & nums, vector < vector < int >> & ans) {
      if (index == nums.size()) {
        ans.push_back(nums);
        return;
      }
      for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        recurPermute(index + 1, nums, ans);
        swap(nums[index], nums[i]);
      }
    }
  public:
    vector < vector < int >> permute(vector < int > & nums) {
      vector < vector < int >> ans;
      recurPermute(0, nums, ans);
      return ans;
    }
};

int main() {
  Solution obj;
  vector < int > v {1,2,3};
  vector < vector < int >> sum = obj.permute(v);
  cout << "All Permutations are" << endl;
  for (int i = 0; i < sum.size(); i++) {
    for (int j = 0; j < sum[i].size(); j++)
      cout << sum[i][j] << " ";
    cout << endl;
  }
}

```
