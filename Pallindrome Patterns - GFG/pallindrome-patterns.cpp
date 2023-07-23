//{ Driver Code Starts



#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	    string reverse(string s){
	        string p ="";
	        for(int i=s.size()-1;i>=0;i--) p+=s[i];
	        return p;
	    }
		vector<string> all_plaindromes(string s)
		{
		    int freq[26]={0};
		    for(auto i:s){
		        freq[i-'a']++;
		    }
		    int cnt = 0;
		    for(int i=0;i<26;i++){
		        if(freq[i]%2) cnt++;
		    }
		  //  cout<<cnt;
		    if(cnt>1) return {};
		    string half ="";
		    char mid;
		    for(int i=0;i<26;i++){
		        if(freq[i]%2) mid = i+'a';
		        half+=string(freq[i]/2,i+'a');
		    }
		    vector<string> ans;
		  //  cout<<half;
            string palin;
            do
            {
                palin = half;
                if (cnt  == 1)
                    palin += mid;
                palin+=reverse(half);
               ans.push_back(palin);
            }
            while (next_permutation(half.begin(), half.end()));
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s;
    	cin >> s;
        Solution ob;
    	vector<string> ans  = ob.all_plaindromes(s);
    	cout<<"{ ";
    	for(auto i: ans)
    		cout << i << " ";
    	cout<<"}";
    	cout<<"\n";
    }
	return 0;
}


// } Driver Code Ends