//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int totalJumps(int x, int y, int n, int height[]){
        int jumps = 0;
 
    for (int i = 0; i < n; i++) {
        if (height[i] <= x) {
            jumps++;
            continue;
        }
 
        /* If height of wall is greater than
           up move */
        int h = height[i];
        while (h > x)
        {
            jumps++;
            h = h - (x - y);
        }
        jumps++;
    }
    return jumps;
    // return jumps;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int X, Y, N;
        cin>>X>>Y>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.totalJumps(X, Y, N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends