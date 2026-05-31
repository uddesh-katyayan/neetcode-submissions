class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if((j-i)<=2){
                    dp[i][j] = s[i]==s[j]? true:false;
                }
                else{
                    dp[i][j] = dp[i+1][j-1] ? s[i] == s[j] : false;
                }
                if(dp[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};
/**
dp[i][j] = true if s[i] == s[j] and dp[i+1][j-1]
dp[i][j] = true if (j-i<=2) s[i] == s[j]
*/