class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>(0, {}));
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<bool> visited(n, false);
        int num_components = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                num_components++;
                dfs(i, visited, graph);
            }
        }
        return num_components;
    }
private:
    void dfs(int i, vector<bool>& visited, vector<vector<int>> graph){
        visited[i] = true;
        vector<int> neighbors = graph[i];
        for(int j=0;j<neighbors.size();j++){
            if(!visited[neighbors[j]]){
                dfs(neighbors[j], visited, graph);
            }
        }
    }
};
