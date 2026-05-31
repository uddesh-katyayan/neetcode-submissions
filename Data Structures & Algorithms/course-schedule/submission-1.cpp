class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>> graph(numCourses, vector<int>(0, 0));
        for(int i=0;i<prereq.size();i++){
            int from = prereq[i][1];
            int to = prereq[i][0];
            graph[from].push_back(to);
        }
        set<int> visited;
        bool status = true;
        for(int i=0;i<numCourses;i++){
            if(visited.find(i)==visited.end()){
                set<int> seen;
                dfs(graph, seen, visited, i, status);
                if(!status){
                    return false;
                }
            }
        }
        return true;
    }
private:
    void dfs(vector<vector<int>> graph, set<int>& seen, set<int>& visited, int node, bool &status){
        seen.insert(node);
        visited.insert(node);
        for(int i=0;i<graph[node].size();i++){
            if(seen.find(graph[node][i])!=seen.end()){
                status = false;
                return;
            }
            if(visited.find(graph[node][i])==visited.end()){
                dfs(graph, seen, visited, graph[node][i], status);
            }
        }
        seen.erase(node);
    }
};
