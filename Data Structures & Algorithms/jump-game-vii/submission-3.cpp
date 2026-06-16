class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> possible(n, false);
        possible[0] = true;
        for(int i=0;i<n;i++){
            if(s[i]=='1')
                continue;
            if(!possible[i])
                continue;
            int mn = i + minJump;
            int mx = min(i + maxJump, n-1);
            for(int j=mn;j<=mx;j++){
                if(s[j]=='0'){
                    if(j==n-1){
                        return true;
                    }
                    // cout << "j: " << j << endl; 
                    possible[j] = true;
                }
            }
        }
        return false;
    }
};