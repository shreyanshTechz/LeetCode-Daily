//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxValue(int arr[], int N) {
        int temp[N],jemp[N];
        for(int i=0;i<N;i++){
            temp[i] = arr[i] - i;
            jemp[i] = arr[i] + i;
        }
        sort(temp,temp+N);
        sort(jemp,jemp+N);
        return max(temp[N-1] - temp[0],jemp[N-1]-jemp[0]);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxValue(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends