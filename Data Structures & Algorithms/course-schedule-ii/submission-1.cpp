class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n, vector<int>(0,{}));
        for(int i=0;i<prerequisites.size();i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            graph[a].push_back(b);
        }
        unordered_set<int> cycle;
        unordered_set<int> visited;
        vector<int> path;
        for(int i=0;i<n;i++){
            if(!dfs(i, graph, cycle, visited, path)){
                return {};
            }
        }
        return path;
    }

private:
    bool dfs(int node, vector<vector<int>> graph, unordered_set<int>& cycle, unordered_set<int>& visited, vector<int>& path){
        cout << " Node: " << node << " count: " << cycle.count(node) << endl;
        if(cycle.count(node)){
            return false;
        }
        if(visited.count(node)){
            return true;
        }
        cycle.insert(node);
        vector<int> prereqs = graph[node];
        for(auto& course: prereqs){
            bool state = dfs(course, graph, cycle, visited, path);
            if(!state){
                return false;
            }
        }
        cycle.erase(node);
        visited.insert(node);
        path.push_back(node);
        return true;
    }
};
