//https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int low=0;
        int sum=0,length=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            while(sum>=target)
            {
                length=min(length,i-low+1);
                sum-=nums[low];
               
               
                low++;
                
            }


        }
        return length==INT_MAX?0:length;
        
    }
};
