//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  string printSubStr(string str, int low, int high)
{
    string s="";
	for (int i = low; i <= high; ++i)
		s+=str[i];
	return s;
}

// Function to find the longest palindromic substring
string longestPalSubstr(string s)
{
	int n = s.length();
	int start = 0, end = 1;
	int low, hi;

	// Traverse the input string
	for (int i = 0; i < n; i++) {

		// Find longest palindromic substring of even size
		low = i - 1;
		hi = i;

		// Expand substring while it is palindrome
		// and in bounds
		while (low >= 0 && hi < n && s[low] == s[hi]) {

			// Update maximum length and starting index
			if (hi - low + 1 > end) {
				start = low;
				end = hi - low + 1;
			}
			low--;
			hi++;
		}

		// Find longest palindromic substring of odd size
		low = i - 1;
		hi = i + 1;

		// Expand substring while it is palindrome
		// and in bounds
		while (low >= 0 && hi < n && s[low] == s[hi]) {

			// Update maximum length and starting index
			if (hi - low + 1 > end) {
				start = low;
				end = hi - low + 1;
			
			}
			low--;
			hi++;
		}
	}

	// Print the longest palindromic substring

	return printSubStr(s, start, start + end - 1);

	// Return output length
// 	return end;
}


    string longestPalin (string S) {
        // code here
        return longestPalSubstr(S);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends