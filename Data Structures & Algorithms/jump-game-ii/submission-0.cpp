class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        vector<int> dp(n,INT_MAX);
        dp[0] = 0;
        for(int i=0;i<n-1;i++){
            int jump = nums[i];
            int max_jump = min(n-1, i+jump);
            for(int j=i+1;j<=max_jump;j++){
                dp[j] = min(dp[j], 1+dp[i]);
            }
        }
        return dp[n-1];
    }
};
/**
dp(i) -> minimum jumps to get to index i
dp(i) = 
*/
