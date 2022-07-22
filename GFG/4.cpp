//https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        int diff=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        diff=nums[k-1]-nums[0];
        for(int i=1,j=k;j<n;i++,j++)
        {
            diff=min(diff,(nums[j]-nums[i]));
            
        }
        return diff;
        
    }
};
