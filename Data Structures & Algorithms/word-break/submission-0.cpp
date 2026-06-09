class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        vector<int> dp(s.size()+1, -1);
        for(auto& word: wordDict){
            wordSet.insert(word);
        }
        int val = dfs(0, s, wordSet, dp);
        return val==1? true : false;
    }
private:
    int dfs(int i, string s, const unordered_set<string> wordSet, vector<int>& dp){
        if(i==s.size()){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int status = 0;
        for(int j=i;j<s.size();j++){
            string substr = s.substr(i, j-i+1);
            if(wordSet.count(substr)){
                int next_status = dfs(j+1, s, wordSet, dp);
                if(next_status==1){
                    status = 1;
                    break;
                }
            }
        }
        dp[i] = status;
        return status;
    }
};
