//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int findLastOccurence(string haystack,string needle){
        int n1=haystack.length();
        int n2=needle.length();
        if(n2==0)
            return 0;
        if(n1==0||n2>n1)
            return -1;
        int lps[n2]={0}; // This is called Longest Prefix which is also a proper suffix.
        //Proper suffix means that in "ABC"- Proper suffixes are "C","BC" and ""(empty). ABC is not included.
        int j=0;
        int i=1;
        while(i<n2){ 
            if(needle[i]==needle[j]){
                lps[i]=j+1;
                i++;
                j++;
            }
            else{
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        i=0;
        j=0;
        int ans = -1;
		//This is the matching Part. Here we will only backtrack pointer j pointing to the pattern and not pointer i which is pointing to the text.
        while(i<n1&&j<n2){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            if(j==n2){
                ans = i-j+1;
                j = lps[j-1];
            }
            else if(haystack[i]!=needle[j]){
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        if(j==n2){
            return i-n2;
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    } 
    return 0; 
}
// } Driver Code Ends