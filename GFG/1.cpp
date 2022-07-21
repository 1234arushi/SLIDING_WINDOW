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

