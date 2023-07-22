//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int tempmax = arr[n-1] , tempmin = arr[0];
        
       // The idea is to increase the first i towers by k and decrease the rest tower by k after sorting the heights, then calculate the maximum height difference.
        //This can be achieved using sorting.
        int ans = tempmax-tempmin;
        for(int i=1; i<n ;i++){
            
            if(arr[i]-k<0) continue;
            // as we have not option to decrese the current height
            // only one option left for it is to increse its height
            
            tempmin = min(arr[0]+k,arr[i]-k);
            // case when we increase every number before curr by k and reduce current by k
            
            tempmax = max(arr[i-1]+k,arr[n-1]-k);
            // case when we decrese every number to right by k 
            
            
            // make sure we are writing arr[i-1] and not arr[i] in next case as we cant consecutively reduce and increse height of curr bar by k
            ans = min(ans, tempmax - tempmin);
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends