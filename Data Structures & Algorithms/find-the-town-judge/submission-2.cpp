class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegrees(n+1, 0);
        vector<int> outdegrees(n+1, 0);
        for(auto& rel: trust){
            indegrees[rel[1]]++;
            outdegrees[rel[0]]++;
        }
        for(int i=1;i<=n;i++){
            if(indegrees[i]==n-1 && outdegrees[i]==0){
                return i;
            }
        }
        return -1;
    }
};