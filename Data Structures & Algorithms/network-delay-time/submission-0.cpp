class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int t = times[i][2];
            graph[u].push_back(make_pair(v, t));
        }
        struct cmp{
            bool operator()(const pair<int, int>& a, const pair<int, int>& b){
                return a.second > b.second;
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> min_heap;
        min_heap.push(make_pair(k,0));
        int total = 0;
        int cur_time = 0;
        int min_time = 0;

        vector<int> visited(n+1, 0);

        while(!min_heap.empty()){
            pair<int, int> top = min_heap.top();
            min_heap.pop();
            int next_node = top.first;
            if(visited[next_node]==1){
                continue;
            }
            visited[next_node] = 1;
            total++;
            min_time = max(min_time, top.second);
            vector<pair<int, int>> edges = graph[next_node];
            for(auto& edge: edges){
                int node = edge.first;
                int time = edge.second;
                if(visited[node]==1){
                    continue;
                }
                min_heap.push(make_pair(node, top.second+time));
            }
        }
        if(total!=n){
            return -1;
        }
        return min_time;
    }
};
