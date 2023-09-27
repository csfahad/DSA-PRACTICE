// Job Sequencing Problem

// PROBLEM LINKS:
// GFG: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
// CODE STUDIO: https://www.codingninjas.com/studio/problems/job-sequencing-problem_1169460


// Approach:  The strategy to maximize profit should be to pick up jobs that offer higher profits. 
// Hence we should sort the jobs in descending order of profit. Now say if a job has a deadline of 4 we can perform it anytime between day 1-4, 
// but it is preferable to perform the job on its last day. This leaves enough empty slots on the previous days to perform other jobs.

// Time Complexity: O(N log N) + O(N*M).
// O(N log N ) for sorting the jobs in decreasing order of profit. 
// O(N*M) since we are iterating through all N jobs and for every job we are checking from the last deadline, say M deadlines in the worst case.

// Space Complexity: O(M) for an array that keeps track on which day which job is performed if M is the maximum deadline available.


#include<iostream>
using namespace std;

// A structure to represent a job 
struct Job {
   int id; // Job Id 
   int dead; // Deadline of job 
   int profit; // Profit if job is over before or on deadline 
};

class Solution {
   public:
      bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
   //Function to find the maximum profit and the number of jobs done
   pair < int, int > JobScheduling(Job arr[], int n) {

      sort(arr, arr + n, comparison);
      int maxi = arr[0].dead;
      for (int i = 1; i < n; i++) {
         maxi = max(maxi, arr[i].dead);
      }

      int slot[maxi + 1];

      for (int i = 0; i <= maxi; i++)
         slot[i] = -1;

      int countJobs = 0, jobProfit = 0;

      for (int i = 0; i < n; i++) {
         for (int j = arr[i].dead; j > 0; j--) {
            if (slot[j] == -1) {
               slot[j] = i;
               countJobs++;
               jobProfit += arr[i].profit;
               break;
            }
         }
      }

      return make_pair(countJobs, jobProfit);
   }
};

int main() {
   int n = 4;
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   //function call
   pair < int, int > ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;

   return 0;
}

