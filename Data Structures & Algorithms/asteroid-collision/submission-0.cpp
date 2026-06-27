class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int cur = INT_MIN;
        vector<int> ans;
        stack<int> S;
        for(int rock: asteroids){
            if(rock > 0){
                S.push(rock);
                continue;
            }
            int cur = rock;
            while(!S.empty()){
                int top = S.top();
                if(top<0){
                    S.push(cur);
                    cur = 0;
                    break;
                }
                if(top == -cur){
                    S.pop();
                    cur = 0;
                    break;
                }
                if(top > -cur){
                    cur = 0;
                    break;
                }
                S.pop();
            }
            if(cur!=0){
                S.push(cur);
            }
        }
        int n = S.size();
        ans.resize(n);
        while(!S.empty()){
            ans[n-- - 1] = S.top();
            S.pop();
        }
        return ans;
    }
};