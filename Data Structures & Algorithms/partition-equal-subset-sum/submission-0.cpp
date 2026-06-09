class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        if(n==0){
            return true;
        }
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
        int target = sum / 2;
        return possibleSum(nums, target);
    }
private:
    bool possibleSum(vector<int> nums, int target){
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        dp[0][0] = 1;
        dp[0][nums[0]] = 1;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<=target;j++){
                if(dp[i][j]==1){
                    dp[i+1][j] = 1;
                    int new_tar = j + nums[i+1];
                    if(new_tar <= target){
                        dp[i+1][new_tar] = 1;
                    }
                }
            }
        }
        return dp[n-1][target] == 1? true : false;
    }
};
