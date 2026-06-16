class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        dp[0][0] = 0;
        for(int i=1;i<=m;i++){
            dp[0][i] = 1 + dp[0][i-1];
        }
        for(int j=1;j<=n;j++){
            dp[j][0] = 1 + dp[j-1][0];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = 1 + min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]);
                if(s[i-1]==t[j-1]){
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }
            }
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=m;j++){
        //         cout << dp[i][j] << "\t";
        //     }
        //     cout << endl;
        // }
        return dp[n][m];
    }
};

/**
dp[i][j] -> Number of ops to convert s(0..i) to t(0..j)
dp[i][j] = 
*/
