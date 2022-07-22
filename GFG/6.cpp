//https://leetcode.com/problems/find-the-k-beauty-of-a-number/submissions/
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        
        
        string str=to_string(num);
        int i=0,j=0,n=str.length();
        int k_beaut=0;
        while(j<n)
        {
            if(j-i+1<k)//until j==k-1
            {
                j++;
            }
            else if(j-i+1==k)
            {
                string s=str.substr(i,k);
                
                int n=stoi(s);
                if(n!=0 && num%n==0)
                {
                    k_beaut++;
                }
                i++;
                j++;
                
            }
        }
        return k_beaut;
        
        
        
        /*my method:
        string str=to_string(num);
        int len=str.length();
        int i=0;
        string substrr=str.substr(i,k);
        int count=0;
        int n=stoi(substrr);
        if(n!=0 && num%n==0)
        {
            count++;
            
        }
        for(int z=1,j=k;j<len;z++,j++)
        {
            substrr=str.substr(j-z,j);
            n=stoi(substrr);
            if(n!=0 && num%n==0)
            {
                count++;
            }
            
            
        }
        return count;*/
        
        
    }
};
