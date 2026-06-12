class Solution {
public:
    int dir[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> min_efforts(n, vector<int>(m, INT_MAX));
        min_efforts[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
                greater<pair<int, pair<int, int>>>> min_heap; // (abs_dist,(row, col))
        min_heap.push(make_pair(0, make_pair(0,0)));
        while(!min_heap.empty()){
            auto [abs_dist, index] = min_heap.top();
            auto [r, c] = index;
            min_heap.pop();
            if(abs_dist > min_efforts[r][c]){
                continue;
            }
            min_efforts[r][c] = abs_dist;
            if(r==n-1 && c==m-1){
                return abs_dist;
            }
            for(int i=0;i<4;i++){
                int r_n = r + dir[i][0];
                int c_n = c + dir[i][1];
                if(c_n < 0 || r_n <0 || c_n >= m || r_n >= n){
                    continue;
                }
                int abs_dist_n = abs(heights[r][c] - heights[r_n][c_n]);
                int effort = max(abs_dist,abs_dist_n);
                if(effort < min_efforts[r_n][c_n]){
                    min_efforts[r_n][c_n] = effort;
                    min_heap.push(make_pair(effort, make_pair(r_n, c_n)));
                }
            }
        }
        return min_efforts[n-1][m-1];
    }
};