class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return s[0] == '0' ? 0:1;
        vector<int> dp(n, 0);
        dp[0] = s[0] == '0' ? 0 : 1;
        int v1_valid = (isValid(s.substr(1,1)) && dp[0]>0) ? 1:0;
        int v2_valid = isValid(s.substr(0,2))? 1:0;
        dp[1] = v1_valid + v2_valid;
        for(int i=2;i<n;i++){
            // cout << "For i:  " << i <<endl;
            cout << "For: " << s.substr(i,1) << " " << isValid(s.substr(i,1)) << endl;
            cout << "For: " << s.substr(i-1,2) << " " << isValid(s.substr(i-1,2)) << endl;
            v1_valid = (isValid(s.substr(i,1)) && dp[i-1]>0) ? dp[i-1]:0;
            v2_valid = isValid(s.substr(i-1,2))? dp[i-2]:0;
            // cout << v1_valid << " " << v2_valid << endl;
            dp[i] = v1_valid + v2_valid;
        }
        // for(int i=0;i<n;i++){
        //     cout<< dp[i] << " ";
        // }
        // cout << endl;
        return dp[n-1];
    }
private:
    bool isValid(string s){
        // cout << "called for: " << s << endl;
        if(s.size()==1){
            if(s[0]=='0')
                return false;
            else{
                return true;
            }
        }
        int i = stoi(s);
        if(i>=10 && i<=26){
            return true;
        }
        return false;
    }
};
/**
dp[i] -> Number of ways s[0..i] could be decoded
dp[i] = dp[i-1] + (if s[i-2].s[i-1] is valid dp[i-2])
dp[0] = 1
dp[1] = is
*/
