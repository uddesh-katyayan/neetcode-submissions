class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        if(m==0 || n==0){
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = text1[0] == text2[0] ? 1 : 0;
        for(int i=1;i<n;i++){
            dp[i][0] = max((text1[i] == text2[0] ? 1:0),dp[i-1][0]);
        }
        for(int i=1;i<m;i++){
            dp[0][i] = max((text1[0] == text2[i] ? 1:0), dp[0][i-1]);
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j] = max(
                    max(dp[i-1][j], dp[i][j-1]),
                    (text1[i] == text2[j] ? 1:0) + dp[i-1][j-1]
                );
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[n-1][m-1];
    }
};
