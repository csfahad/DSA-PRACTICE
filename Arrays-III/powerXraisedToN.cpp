// Implement Pow(x,n) | X raised to the power N



// BRUTEFORCE APPROACH

// Approach:  Looping from 1 to n and keeping a ans(double) variable. 
// Now every time your loop runs, multiply x with ans. At last, we will return the ans.
// Now if n is negative we must check if n is negative, if it is negative divide 1 by the and.

// Time Complexity: O(N)
// Space Complexity: O(1)


#include<iostream>
using namespace std;

double myPow(double x, int n) {
      double ans = 1.0;
      for (int i = 0; i < n; i++) {
        ans = ans * x;
      }
      return ans;
}

int main() {
    cout<<myPow(2,10)<<endl;
}



// OPTIMAL APPROACH : USING BINARY EXPONENTIATION

// Time Complexity: O(log n)
// Space Complexity: O(1)


#include<iostream>
using namespace std;

double myPow(double x, int n) {
  double ans = 1.0;
  long long nn = n;
  if (nn < 0) nn = -1 * nn;
  while (nn) {
    if (nn % 2) {
      ans = ans * x;
      nn = nn - 1;
    } else {
      x = x * x;
      nn = nn / 2;
    }
  }
  if (n < 0) ans = (double)(1.0) / (double)(ans);
  return ans;
}

int main() {
  cout << myPow(2, 10) << endl;
}