class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> dp(m+1, 0);
        for(int i=0;i<n;i++){
            dp[0] = i==0 ? 1:0;
            for(int j=1;j<=m;j++){
                dp[j] = grid[i][j-1] == 1 ? 0 : dp[j-1] + dp[j];
            }
            for(int j=1;j<=m;j++){
                cout << dp[j] << "\t";
            }
            cout << endl;
        }
        return dp[m];
    }
};