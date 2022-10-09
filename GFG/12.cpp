//https://leetcode.com/problems/subarray-product-less-than-k/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        
        if(k<=1)//k<=1 cuz...all elements are "+" so there product will not be less 
            //than 1 and less than even 1
        {
            return 0;
        }
        int prod=1,count=0,l=0;
        for(int r=0;r<nums.size();r++)
        {
            prod*=nums[r];
            while(prod>=k)
            {
                prod/=nums[l];
                l++;
            }
            count+=r-l+1;
        }
        return count;
        
    }
};
