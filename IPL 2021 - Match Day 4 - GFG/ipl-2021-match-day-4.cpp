//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
 
class Solution
{
    public:
    // Function for finding maximum AND value.
    int maxAND (int arr[], int n)
    {
        int res = 0 , pat = 0;
        // res stores the answer -> max and of two numbers
        // pat stores the pattern generated so far
        for(int i=30;i>=0;i--){
            pat += (1<<i);
            int cnt = 0;
            for(int j=0;j<n;j++){
                if((arr[j] & pat) >= pat) cnt++;
            }
            if(cnt>=2){
                res = pat;
            }
            else pat-=(1<<i);
        }
        return res;
    }
};

//{ Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends