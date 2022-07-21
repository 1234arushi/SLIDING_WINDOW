//https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-group-all-1s-together2451/1
//{ Driver Code Starts
// C++ program to find minimum swaps
// required to group all 1's together
#include <bits/stdc++.h>

using namespace std;

// Function to find minimum swaps
// to group all 1's together
int minSwaps(int arr[], int n) ;


// Driver Code
int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << minSwaps(a, n)<<endl;
    
    }

    return 0;
}

// } Driver Code Ends


int minSwaps(int arr[], int n) {
    
    int ones_count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            ones_count++;
        }
    }
    if(ones_count==0)
    {
        return -1;
    }
    int zeros_count=0;
    //first window
    for(int i=0;i<ones_count;i++)
    {
        if(arr[i]!=1)
        {
            zeros_count++;
        }
    }
    int swaps=zeros_count;
    //sliding windows;
    for(int i=0,j=ones_count;j<n;j++,i++)
    {
        if(arr[i]==0)
        {
            zeros_count--;
        }
        if(arr[j]==0)
        {
            zeros_count++;
        }
        swaps=min(swaps,zeros_count);
    }
   
    return swaps;
    
    
    // Complete the function
    
}
