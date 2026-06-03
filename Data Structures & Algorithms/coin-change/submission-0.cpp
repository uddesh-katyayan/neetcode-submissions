class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        int n = coins.size();
        vector<int> dp(target+1, 0);
        dp[0] = 0;
        for(int i=0;i<n;i++){
            if(coins[i]<=target)
                dp[coins[i]] = 1;
        }
        for(int i=1;i<=target;i++){
            if(dp[i]==1)
                continue;
            int min_coins = INT_MAX;
            for(auto coin: coins){
                int prev_target = i - coin;
                if(prev_target >= 0){
                    min_coins = min(min_coins, dp[prev_target]);
                }
            }
            dp[i] = min_coins == INT_MAX ? INT_MAX : 1+min_coins;
        }
        for(int i=0;i<=target;i++){
            cout << dp[i] << "\t";
        }
        cout << endl;
        return dp[target] == INT_MAX ? -1 : dp[target];
    }
};
