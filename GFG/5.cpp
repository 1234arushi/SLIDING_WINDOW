//https://leetcode.com/problems/maximum-average-subarray-i/submissions/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        double avg=0;
        int n=nums.size();
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
            
        }
        avg=double(sum)/k;
        double max_avg=avg;
        for(int i=0,j=k;j<n;j++,i++)
        {
            sum+=nums[j]-nums[i];
            avg=double(sum)/k;
            max_avg=max(max_avg,avg);
                
            
        }
        return max_avg;
        
    }
};
