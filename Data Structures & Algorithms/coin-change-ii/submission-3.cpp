class Solution {
public:
    int change(int target, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                int coin = coins[i-1];
                for(int k=0;k<=target;k+=coin){
                    int cur_target = j+k;
                    if(cur_target <= target){
                        dp[i][cur_target] += dp[i-1][j];
                    }
                }
            }
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=target;j++){
        //         cout << dp[i][j] << "\t";
        //     }
        //     cout<<endl;
        // }
        return dp[n][target];
    };
};
