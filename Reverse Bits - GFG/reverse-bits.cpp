//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long X) {
        unsigned int ans = 0;
        for(int i=0;i<32;i++){
            if(((X>>i) & 1)){
                // cout<<i<<" ";
                ans|=abs(1<<(31-i));
                // cout<<ans<<" ";
            }
        }
        return abs(ans);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends