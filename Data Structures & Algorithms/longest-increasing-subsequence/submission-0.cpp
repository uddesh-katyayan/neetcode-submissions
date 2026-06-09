class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        int max_lis_len = 1;
        for(int i=0;i<n;i++){
            int max_len = 1;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    int lis_len = dp[j] + 1;
                    max_len = max(max_len, lis_len);
                }
            }
            dp[i] = max_len;
            max_lis_len = max(max_lis_len, max_len);
        }
        return max_lis_len;
    }
};
