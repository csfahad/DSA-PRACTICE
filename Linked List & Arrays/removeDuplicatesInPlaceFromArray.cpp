// Remove Duplicates in-place from Sorted Array

// PROBLEM LINKS:
// LEETCODE: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// CODESTUDIO: https://www.codingninjas.com/studio/problems/1102307



// BRUTEFORCE APPROACH:

// Time complexity: O(n*log(n))+O(n)
// Space Complexity: O(n) 


#include<iostream>
#include<set>
using namespace std;

int removeDuplicates(int arr[], int n) {
  set <int> set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  return k;
}

int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}



// OPTIMAL APPROACH : USING TWO POINTER APPROACH

// Time Complexity: O(N)
// Space Complexity: O(1)


#include<iostream>
using namespace std;

int removeDuplicates(int arr[], int n) {
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}

int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}

