// Find minimum number of coins

// PROBLEM LINK: https://www.codingninjas.com/studio/problems/find-minimum-number-of-coins_975277


// GREEDY ALGORITHM

// Time Complexity:O(V)
// Space Complexity:O(1)


#include<iostream>
#include<vector>
using namespace std;

int main() {
  int V = 49;
  vector <int> ans;
  int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int n = 9;
  for (int i = n - 1; i >= 0; i--) {
    while (V >= coins[i]) {
      V -= coins[i];
      ans.push_back(coins[i]);
    }
  }
  cout<<"The minimum number of coins is "<<ans.size()<<endl;
  cout<<"The coins are "<<endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}