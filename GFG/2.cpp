//https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1
//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int fav=0;//no. of elements(<=k) that we need to put together
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=k)
            {
                fav++;
            }
            
        }
        int nonfav=0;
        //checking in first window  nonfav elemest(=swaps)
        for(int i=0;i<fav;i++)
        {
            if(arr[i]>k)
            {
                nonfav++;
            }
        }
        int swaps=nonfav;
        //next windows
        
        //checking elements (>k) in every window of size :the elments <=K
        //and counting them in each window and finding min in all
        for(int i=0,j=fav;j<n;i++,j++)
        {
            //arr[i]->remove
            if(arr[i]>k)//previous window element if it is greater than k
            //then only reduce the nonfav count bcz we are considering another 
            //window and we need to find nonfav in that window not taking
            //previous count
            //if(arr[i]<k)->nonfav as it is bcz earlier also that didnt
            //contribute to nonfav and now also it wont
            {
                nonfav--;
            }
            //arr[j]->add
            if(arr[j]>k)
            {
                nonfav++;
            }
            swaps=min(swaps,nonfav);
        }
        return swaps;
        // Complet the function
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends
