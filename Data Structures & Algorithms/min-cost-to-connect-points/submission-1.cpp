class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> dist(n, INT_MAX);
        int min_cost = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        dist[0] = 0;
        vector<int> cur_point = points[0];
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n;j++){
                if(dist[j]!=INT_MAX){
                    continue;
                }
                int d = calculate_dist(cur_point, points[j]);
                // cout << "cost from: (" << cur_point[0] << "," << cur_point[1] << ") to (" << points[j][0] << "," << points[j][1] << ") is: " << d << endl;
                min_heap.push({d, j});
            }
            while(!min_heap.empty()){
                auto top = min_heap.top();
                // cout << "Point popped: (" << points[top.second][0] << "," << points[top.second][1] << "). with dist: " << top.first << endl;
                min_heap.pop();
                if(dist[top.second]!=INT_MAX)
                    continue;
                cur_point = points[top.second];
                dist[top.second] = top.first;
                min_cost += top.first;
                break;
            }
            
            // for(int k=0;k<n;k++){
            //     cout << dist[k] << "\t";
            // }
            // cout << endl;
        }

        return min_cost;
    }
private:
    int calculate_dist(vector<int>& p1, vector<int>& p2){
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }
};
