//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  bool isPossible(int arr[], int n, int m, int curr_min)
{
    int studentsRequired = 1;
    int curr_sum = 0;
 
    // iterate over all books
    for (int i = 0; i < n; i++) {
        // check if current number of pages are greater
        // than curr_min that means we will get the result
        // after mid no. of pages
        if (arr[i] > curr_min)
            return false;
 
        // count how many students are required
        // to distribute curr_min pages
        if (curr_sum + arr[i] > curr_min) {
            // increment student count
            studentsRequired++;
 
            // update curr_sum
            curr_sum = arr[i];
 
            // if students required becomes greater
            // than given no. of students,return false
            if (studentsRequired > m)
                return false;
        }
 
        // else update curr_sum
        else
            curr_sum += arr[i];
    }
    return true;
}
 
  
  
  
  
    long long minTime(int arr[], int n, int k)
    {
        long long sum = 0;
    if (n < k)
        k = n;
    int mx = INT_MIN;
 
    // Count total number of pages
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        mx = max(mx, arr[i]);
    }
 
    // initialize start as 0 pages and end as
    // total pages
    long long  start = mx, end = sum;
    long long result = INT_MAX;
 
    // traverse until start <= end
    while (start <= end) {
        // check if it is possible to distribute
        // books by using mid as current minimum
        int mid = (start + end) / 2;
        if (isPossible(arr, n, k, mid)) {
            // update result to current distribution
            // as it's the best we have found till now.
            result = mid;
 
            // as we are finding minimum and books
            // are sorted so reduce end = mid -1
            // that means
            end = mid - 1;
        }
 
        else
            // if not possible means pages should be
            // increased so update start = mid + 1
            start = mid + 1;
    }
 
    // at-last return minimum no. of  pages
    return result;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends