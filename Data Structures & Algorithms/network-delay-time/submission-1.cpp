class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto& edge: times){
            graph[edge[0]].push_back(make_pair(edge[2], edge[1]));
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        min_heap.push(make_pair(0, k));
        int total = 0;
        int min_time = 0;

        vector<bool> visited(n+1, false);

        while(!min_heap.empty()){
            auto [dist, node] = min_heap.top();
            min_heap.pop();

            if(visited[node]){
                continue;
            }
            visited[node] = true;
            total++;
            min_time = max(min_time, dist);
            for(auto& edge: graph[node]){
                auto [next_dist, next_node] = edge;
                if(visited[next_node]){
                    continue;
                }
                min_heap.push(make_pair(next_dist+dist, next_node));
            }
        }
        if(total!=n){
            return -1;
        }
        return min_time;
    }
};
