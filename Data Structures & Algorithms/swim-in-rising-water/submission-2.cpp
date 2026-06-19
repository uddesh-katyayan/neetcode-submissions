class Solution {
    int dir[4][2] = {{-1, 0}, {1, 0}, {0,1}, {0, -1}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> min_heap;
        vector<vector<int>> dist(n, vector<int>(m, -1));
        min_heap.push({grid[0][0],{0,0}});
        int new_i, new_j, new_dist;
        while(!min_heap.empty()){
            auto top = min_heap.top();
            min_heap.pop();
            int cur_dist = top.first;
            auto [i, j] = top.second;
            if(dist[i][j]==-1)
                dist[i][j] = cur_dist;
            else
                continue;
            for(int k=0;k<4;k++){
                new_i = i + dir[k][0];
                new_j = j + dir[k][1];
                if(new_i <0 || new_i>=n || new_j <0 || new_j >=m){
                    continue;
                }
                // Already the min dist has been set, no extra improvements could be made
                if(dist[new_i][new_j]!=-1){
                    continue;
                }
                new_dist = max(cur_dist, grid[new_i][new_j]);
                min_heap.push({new_dist, {new_i, new_j}});
            }
        }
        return dist[n-1][m-1];
    }
};

/**
dp[i][j] -> Min path cost to reach i, j (cost is the highest tower in the path)
dp[i][j] = max
            -grid[i][j]
            -min(dp[i-1][j], dp[i][j-1], dp[i+1][j], dp[i][j+1])
*/
