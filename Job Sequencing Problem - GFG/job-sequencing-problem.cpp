//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comparator(Job a,Job b){
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr + n ,comparator); // sort the job in descending order of profit
        int slot[n];
        vector<int> result(n);
        for(int i=0;i<n;i++) slot[i] = false;
        for(int i=0;i<n;i++){
            // for each job search for highest deadline slot
            for(int j = min(n,arr[i].dead)-1;j>=0;j--){
                if(!slot[j]){
                    slot[j] = true;
                    result[j]=i; // store the index of job in the corresponding slot which is selscted
                    break;
                }
            }
        }
        vector<int> ans(2); // to store the answer
        int sum = 0,count=0;
        for(int i=0;i<n;i++){
            if(slot[i]){ // if that slot is occupied.
                sum+=arr[result[i]].profit; 
                count++;
            }
        }
        ans[0] = count; ans[1] = sum;
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends