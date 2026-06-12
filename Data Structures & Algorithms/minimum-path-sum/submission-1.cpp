class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0)
            return 0;
        int m = grid[0].size();
        if(m==0){
            return 0;
        }
        vector<int> dp(m);
        int min_sum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    dp[j] = min_sum + grid[i][j];
                    min_sum = dp[j];
                } else {
                    dp[j] = (j==0 ? dp[j] : min(min_sum, dp[j])) + grid[i][j];
                    min_sum = dp[j];
                }
                cout << dp[j] << " ";
            }
            min_sum = 0;        
            cout << endl;
        }
        return dp[m-1];
    }
};