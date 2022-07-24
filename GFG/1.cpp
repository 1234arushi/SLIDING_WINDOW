//https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1?page=1&category[]=sliding-window&sortBy=submissions
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        
        long long sum=0,maxsum=0;
        //first window
        for(int i=0;i<K;i++)
        {
            sum+=Arr[i];
        }
        
        maxsum=sum;
        //subsequent windows
        for(int i=0,j=K;j<N;j++,i++)
        {
            sum+=Arr[j]-Arr[i];
            
            maxsum=max(maxsum,sum);
        }
        return maxsum;
        
        // code here 
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends





















//Given an array of integers of size ‘n’, 
//Our aim is to calculate the maximum sum of ‘k’ consecutive elements 
//in the array.

#include<bits/stdc++.h>
using namespace std;

int maxsum(int arr[],int n,int k)
{
    if(k>n)//n must be greater
    {
        cout<<"Invalid";
        return -1;
    }
    int max_sum=0;
    //compute sum of first window of size k
    for(int i=0;i<k;i++)
    {

        max_sum+=arr[i];
    }
    //compute sums of remaining windows by removing first element of previous window and adding last element of current window
    int window_sum=max_sum;
    for(int i=k;i<n;i++)
    {

        window_sum+=arr[i]-arr[i-k];
        max_sum=max(max_sum,window_sum);
    }
    return max_sum;

}
int main()
{
    int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxsum(arr, n, k);
    return 0;

    return 0;
}

