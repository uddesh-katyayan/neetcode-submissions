class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue<pair<double, int>, 
            vector<pair<double, int>>,
                less<pair<double, int>>> max_heap;
        vector<vector<pair<double, int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({succProb[i], edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }
        max_heap.push({1.0, start});
        vector<double> mx_prob(n, -1);
        while(!max_heap.empty()){
            auto [prob, node] = max_heap.top();
            max_heap.pop();
            mx_prob[node] = prob;
            if(node == end){
                return prob;
            }
            for(auto edge: adj[node]){
                if(mx_prob[edge.second]==-1){
                    max_heap.push({prob*edge.first, edge.second});
                }
            }
        }
        return 0;
    }
};