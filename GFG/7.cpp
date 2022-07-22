//https://practice.geeksforgeeks.org/problems/substrings-of-length-k-with-k-1-distinct-elements/1?page=2&category[]=sliding-window&sortBy=submissions
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string S, int K) {
        
        unordered_map<char,int> m;
        int count=0;
        
        //first window
        for(int i=0;i<K;i++)
        {
            m[S[i]]++;
            
        }
        if(m.size()==K-1)
        {
            count++;
        }
        
        //sliding windows:subsequent windows
        for(int i=0,j=K;j<S.size();i++,j++)
        {
            //sliding
            m[S[j]]++;//Increase the frequency of the last character 
                         //of the current substring 
            m[S[i]]--;// Decrease the frequency of the first character 
                       //of the previous substring 
            
            //If the character is not present in the current substring
            if(m[S[i]]==0)
            {
                m.erase(S[i]);
            }
            if(m.size()==K-1)
            {
                count++;
            }
        }
        return count;
        
        
        
        /*my method:TLE
        int i=0,j=0,n=S.length();
        int count=0;
        while(j<n)
        {
            if(j-i+1<K)//j=k-1
            {
                j++;
            }
            else if(j-i+1==K)
            {
                string sub=S.substr(i,K);
                unordered_set<int> s;
                for(int x=0;x<K;x++)
                {
                    s.insert(sub[x]);
                    
                }
                if(s.size()==K-1)
                {
                    count++;
                }
                i++;j++;
            }
        }
        return count;*/
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends
