# N Queen Problem | Return all Distinct Solutions to the N-Queens Puzzle

## Problem links :

### [Leetcode](https://leetcode.com/problems/n-queens/)

### [CodeStudio](https://www.codingninjas.com/studio/problems/759332)

## Approach 1 - Recursion + Bactracking

**Intuition:** Using the concept of Backtracking, we will place Queen at different positions of the chessboard and find the right arrangement where all the n queens can be placed on the n\*n grid.

**Ist position:** This is the position where we can see no possible arrangement is found where all queens can be placed since, at the 3rd column, the Queen will be killed at all possible positions of row.

<img src="https://lh5.googleusercontent.com/yBKXh7WgcSe7NpVF4SBBHJdXe7zRCPtrRBorJq37lXlal8t1kflUPRBgT0BmLr27ythWhkRC9gLOGpH5ZMpSEAzPKKqccLJD7u8te1lQ-hIP53w6-anQsrDx0V11DJMFOJBC-rKy" alt="1st position" width="800"/>

<p>&nbsp;</p>

**2nd position:** One of the correct possible arrangements is found. So we will store it as our answer.

<img src="https://lh4.googleusercontent.com/FyMuuvj4K8HMHR7hpbOdWkGTX3-0PmUVG0kaWjUfWWIKp0Uth2CVlGfsBQtmQ-NkKB-Z2I9I20KpVZ_DU0bCayJDQ_pcyJHT0pCHA4jMPqc6ObW97FjOXHiQSYC8MC5OV1xgwZJP" alt="2nd position" width="800"/>

<p>&nbsp;</p>

**3rd position:** One of the correct possible arrangements is found. So we will store it as our answer.

<img src="https://lh5.googleusercontent.com/cAOExJ4tnI-01-My0KL5OCZlVVqb6aLJDAlgUZs-Uv8tpH0tkLQKWLJugaET3FTp5y-9ilt5jGq1ZY83oncqbB9H-aCFutnGdsHXnGsmR3JDEsitZrqhMh2g0ORrPOz2dYuGg2tl" alt="3rd position" width="800"/>

<p>&nbsp;</p>

**4th position:** This is the position where we can see no possible arrangement is found where all queens can be placed since, at the 4th column, the Queen will be killed at all possible positions of row.

<img src="https://lh6.googleusercontent.com/h_tzrr-D4aTEGXNxjCd3hvjVRc3DRK57clMNGWKC6m-jDTb2tViEfodjVaxs-2djvlwCMXvTjcv-xqnxpY5GEb-iWiAiQxdtkTNUuSzIeqJau_dDN9aj3LJfls-BuMMd7RT2Jsdu" alt="4th position" width="800"/>

<p>&nbsp;</p>

**Time Complexity:** Exponential in nature, since we are trying out all ways. To be precise it goes as O(N! \* N) nearly.

**Space Complexity:** O(N^2)

**Code :**

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isSafe1(int row, int col, vector < string > board, int n) {
      // check upper element
      int duprow = row;
      int dupcol = col;

      while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
    }

  public:
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (isSafe1(row, col, board, n)) {
          board[row][col] = 'Q';
          solve(col + 1, board, ans, n);
          board[row][col] = '.';
        }
      }
    }

  public:
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      solve(0, board, ans, n);
      return ans;
    }
};
int main() {
  int n = 4; // we are taking 4*4 grid and 4 queens
  Solution obj;
  vector < vector < string >> ans = obj.solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}

```

## Approach 2 - Recursion + Hashing

**Intuition:** This is the optimization of the issafe function. In the previous issafe function, we need o(N) for a row, o(N) for the column, and o(N) for the diagonal. Here, we will use hashing to maintain a list to check whether that position can be the right one or not.

**For checking Left row elements**

<img src="https://lh6.googleusercontent.com/UZm_6j1v5WQYlA0Y7wMo4LObyB2TdWcWGeZegccZ9VxeDkgf3en9IG9-gnSKtZLAH3b0auF75tyc0oNWC6J1_MFgeqKOGsvQTny6nBD2padF6sISb0LWv16wj9Acy3-Q-4gU_FlB" alt="4th position" width="800"/>

<p>&nbsp;</p>

**For checking upper diagonal and lower diagonal**

<img src="https://lh6.googleusercontent.com/cu5CY5IuyBkkiPmZDoYFF92lQL5PsKxndb_me-btV-sTD_jYE4dVmNrcCvo3ES2IpJeudhCaioqnSG8QqaO-vX64EAXkwcBfaZ0dC1qmHooXpmkicyeKBe1WW1Ldcw6dnYaGdUFx" alt="4th position" width="800"/>

<p>&nbsp;</p>

**Time Complexity:** Exponential in nature since we are trying out all ways, to be precise it is O(N! \* N).

**Space Complexity:** O(N)

**Code :**

```cpp

#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
          board[row][col] = 'Q';
          leftrow[row] = 1;
          lowerDiagonal[row + col] = 1;
          upperDiagonal[n - 1 + col - row] = 1;
          solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
          board[row][col] = '.';
          leftrow[row] = 0;
          lowerDiagonal[row + col] = 0;
          upperDiagonal[n - 1 + col - row] = 0;
        }
      }
    }

  public:
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
      solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
      return ans;
    }
};
int main() {
  int n = 4; // we are taking 4*4 grid and 4 queens
  Solution obj;
  vector < vector < string >> ans = obj.solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}

```
