class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(auto& edge: prerequisites){
            adj[edge[0]].push_back(edge[1]);
        }
        vector<bool> ans;
        for(auto& q: queries){
            vector<bool> visited(n);
            visited[q[0]] = true;
            ans.push_back(dfs(q[0], q[1], adj, visited));
        }
        return ans;
    }
private: 
    bool dfs(int i, int j, vector<vector<int>>& adj, vector<bool>& visited){
        if(i==j){
            return true;
        }
        for(auto& nbr: adj[i]){
            if(visited[nbr])
                continue;
            visited[nbr] = true;
            bool status = dfs(nbr, j, adj, visited);
            if(status)
                return true;
        }
        return false;
    }
};