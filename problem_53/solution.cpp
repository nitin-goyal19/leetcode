class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int sum = 0;
        
        for(int i = 0; i < n; ++i) {
            sum = max(sum + nums[i], nums[i]);
            if(sum < 0){
                sum = min(sum, nums[i]);
            }
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};