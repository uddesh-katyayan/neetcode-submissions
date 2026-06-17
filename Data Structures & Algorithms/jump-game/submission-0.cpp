class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        for(int i=0;i<n;i++){
            if(!dp[i]){
                continue;
            }
            for(int j=i;j<=i+nums[i];j++){
                if(j==n-1){
                    return true;
                }
                dp[j] = true;
            }
        }
        return false;
    }
};

/*
dp[i] -> if possible to reach index i from 0
dp[i]
*/
