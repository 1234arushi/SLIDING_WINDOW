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
        
        
        
        /*my method:error?!!!!!!!!!!1
        string str=to_string(num);
        int len=str.length();
        
        string substrr=str.substr(0,k);//first window
        int n=stoi(substrr);
        
        int count=0;
        
        // cout<<n<<" ";
        if(n!=0 && num%n==0)
        {
            count++;
           
            
        }
       //subsequent windows 
        for(int i=1;i<len;i++)
        {
            
            substrr=str.substr(i,k);i++;
            n=stoi(substrr);
            cout<<n<<" ";
            //cout<<n<<" ";
            if(n!=0 && num%n==0)
            {
                
                count++;
            }
            
            
        }
        return count;*/
        
        
    }
};
