//https://leetcode.com/problems/subarray-product-less-than-k/submissions/846848716/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //as we have postive integers in array so prod will not 
        //be less than = to 1
        if(k<=1)//gives runtime error if not applied
        {
            return 0;
        }
        
        int prod=1,i=0,count=0;
        for(int j=0;j<nums.size();j++)
        {
            prod*=nums[j];
            while(prod>=k)
            {
                prod/=nums[i++];
            }
            count+=j-i+1;
        }
        return count;
        
    }
};
