class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        if(n==0){
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        int M = 2*sum+1;
        vector<vector<int>> dp(n, vector<int>(M, 0));
        dp[0][sum+nums[0]] += 1;
        dp[0][sum-nums[0]] += 1;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<M;j++){
                if(dp[i][j]>0){
                    // if(nums[i]>0){
                        dp[i+1][j-nums[i+1]] += dp[i][j];
                        dp[i+1][j+nums[i+1]] += dp[i][j];
                    // }
                    // else{
                    //     dp[i+1][j] += dp[i][j];
                    // }
                }
            }
        }
        for(int i=-1;i<n;i++){
            for(int j=0;j<M;j++){
                if(i==-1){
                    cout << j-sum << "\t";
                }
                else{
                    cout << dp[i][j]<< "\t";
                }
            }
            cout << endl;
        }
        if(target>sum){
            return 0;
        }
        return dp[n-1][sum+target];
    }
};
