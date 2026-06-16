class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        if(n==0){
            return false;
        }
        vector<int> prefix_sum(n+1, 0);
        for(int i=1;i<n;i++){
            prefix_sum[i] = prefix_sum[i-1] + piles[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j)
                    dp[i][j] = piles[i];
                else{
                    dp[i][j] = max(
                        piles[i] + prefix_sum[j+1] - prefix_sum[i+1] - dp[i+1][j],
                        piles[j] + prefix_sum[j] - prefix_sum[i] - dp[i][j-1]
                    );
                }
            }
        }
        if(dp[0][n-1]>=(prefix_sum[n])/2)
            return true;
        return false;
    }
};

/*
dp[i][j] = max score a player can get
dp[i][j] = max
            1. piles[i] + sum(i+1..j) - dp[i+1][j]
            2. piles[j] + sum(i..j-1) - dp[i][j-1];
            i<=j
*/