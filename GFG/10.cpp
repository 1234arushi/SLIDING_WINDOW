//https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1?page=1&category[]=sliding-window&sortBy=submissions
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        //how sliding window applied here?
        unordered_map<int,int> m;
        int sum=0;
        int longest_subarray=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i]==0?-1:1;
            if(sum==0)//len=starting index to current index
            {
                //checking and then updating
                /*if(longest_subarray<i+1)
                {
                   longest_subarray=max(longest_subarray,i+1);
                    
                }*/
                longest_subarray=max(longest_subarray,i+1);
            }
            //if prefix sum appears again in map then there is
            //a subarray that has sum=0 (equal no of 0s and 1s)
            //and its length will be current index-first index
                                    //(where sum appeared again)
            else if(m.find(sum)!=m.end())
            {
                longest_subarray=max(longest_subarray,i-m[sum]);
            }
            //that sum is not in map,so include it
            else
            {
                m[sum]=i;
                
                
            }
        }
        return longest_subarray;
        // Your code here
    }
};


//{ Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
