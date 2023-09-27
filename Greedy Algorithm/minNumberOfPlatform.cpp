// Minimum number of platforms required for a railway

// PROBLEM LINKS:
// GFG: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
// CODE STUDIO: https://www.codingninjas.com/studio/problems/minimum-number-of-platforms_799400


// BRUTEFORCE APPROACH

// Intuition: Take each interval of arrival and departure one by one and count the number of overlapping time intervals. 
// This can easily be done using nested for-loops. Maintain the maximum value of the count during the process and return the maximum value at the end.


// Time Complexity: O(n^2)  (due to two nested loops).
// Space Complexity: O(1)  (no extra space used).



#include<iostream>
 using namespace std;
 
 int countPlatforms(int n,int arr[],int dep[]) {
    int ans=1; //final value
    for(int i=0;i<=n-1;i++) {
        int count=1; // count of overlapping interval of only this   iteration
        for(int j=i+1;j<=n-1;j++) {
            if((arr[i]>=arr[j] && arr[i]<=dep[j]) ||
            (arr[j]>=arr[i] && arr[j]<=dep[i])) {
               count++;
           }
        }
        ans=max(ans,count); //updating the value
    }
    return ans;
 }
 
 int main() {
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<countPlatforms(n,arr,dep)<<endl;
 }




//  OPTIMAL APPROACH : USING SORTING

// Intuition: At first we need to sort both arrays. When the events will be sorted, 
// it will be easy to track the count of trains that have arrived but not departed yet. 
// The total platforms needed at one time can be found by taking the difference between 
// arrivals and departures at that time and the maximum value of all times will be the final answer.


// Time Complexity: O(nlogn) Sorting takes O(nlogn) and traversal of arrays takes O(n) so overall time complexity is O(nlogn).
// Space complexity: O(1)  (No extra space used).



#include<iostream>
using namespace std;

int countPlatforms(int n,int arr[],int dep[]) {
    sort(arr,arr+n);
    sort(dep,dep+n);

    int ans=1;
    int count=1;
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j]) //one more platform needed
        {
            count++;
            i++;
        }
        else //one platform can be reduced
        {
            count--;
            j++;
        }
        ans=max(ans,count); //updating the value with the current maximum
    }
    return ans;
}

int main() {
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<countPlatforms(n,arr,dep)<<endl;
}