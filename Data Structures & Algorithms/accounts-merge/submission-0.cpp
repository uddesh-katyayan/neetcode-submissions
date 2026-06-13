class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        // There are n nodes initially
        unordered_map<string, vector<int>> email_mappings;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email = accounts[i][j];
                if(email_mappings.count(email)){
                    for(int& node: email_mappings[email]){
                        adj[i].push_back(node);
                        adj[node].push_back(i);
                    }
                }
                email_mappings[email].push_back(i);
            }
        } 
        vector<int> visited(n, -1);
        int comp = 1;
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                dfs(i, adj, visited, comp++);
            }
        }
        for(int i=0;i<n;i++){
            cout << visited[i] << "\t";
        }
        vector<vector<string>> ans;
        for(int i=1; i<comp; i++){
            set<string> emails;
            string name;
            for(int j=0;j<n;j++){
                if(visited[j]==i){
                    name = accounts[j][0];
                    emails.insert(accounts[j].begin()+1, accounts[j].end());
                }
            }
            vector<string> current = {name};
            current.insert(current.end(), emails.begin(), emails.end());
            ans.push_back(current);
        }
        return ans;
    }
private:
    void dfs(int i, vector<vector<int>> adj, vector<int>& visited, int comp){
        visited[i] = comp;
        for(int& nbr: adj[i]){
            if(visited[nbr]==-1){
                dfs(nbr, adj, visited, comp);
            }
        }
    }
};