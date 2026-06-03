class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>(0, {}));
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            if(a==b)
                return false;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<bool> visited(n, false);
        bool is_tree = true;
        is_tree = dfs(0, 0, visited, graph);
        for(int i=1;i<n;i++){
            if(!visited[i])
                return false;
        }
        return is_tree;
    }
private:
    bool dfs(int i, int last, vector<bool>& visited, vector<vector<int>>& graph){
        // cout << "i: " << i << endl;
        visited[i] = true;
        vector<int> neighbors = graph[i];
        for(int j=0;j<neighbors.size();j++){
            int cur = neighbors[j];
            // cout << "cur: "<< cur << endl;
            if(cur == last){
                continue;
            }
            if(visited[cur]){
                // cout << "Returning: false1" << endl; 
                return false;
            }
            bool next_dfs = dfs(cur, i, visited, graph);
            if(!next_dfs){
                // cout << "Returning: false2" << endl; 
                return false;
            }
        }
        // cout << "Returning: true" << endl; 
        return true;
    }
};
