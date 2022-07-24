//https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?page=1&category[]=sliding-window&sortBy=submissions
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        //similar to largest subarray with equal no. of 0s and 1s
        //or largest subarray with sum=0
        //another method:TC->O(N)  SC->O(N)
        //this works for negative/positive numbers
        unordered_map<int,int> m;
        int sum=0,len=0;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            
            if(sum==K)
            {
                len=i+1;//subarray with sum of elements =K starts from index 0
                
            }
            if(m.find(sum)==m.end())//if we don't find that prefix-sum in map
            {
                m[sum]=i;
            }
            if(m.find(sum-K)!=m.end())//if sum-K exists in map
            //then it means we got another subarray with sum=K
            {
                len=max(len,i-m[sum-K]);
                
            }
        }
        return len;
        
        
        /*my method:approach won’t work for negative numbers???
        //dry run it as how does it not work for negative numberss
        int start=0,sum=0,len=0;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            while(sum>K )//purpose of start<i??
            {
                sum=sum-A[start];
                start++;
            }
            if(sum==K)
            {
                cout<<A[start]<<" "<<A[i];
                len=max(len,i-start+1);
                
            }
        }
        return len;*/
        // Complete the function
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
