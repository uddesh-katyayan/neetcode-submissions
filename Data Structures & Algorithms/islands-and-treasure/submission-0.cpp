class Solution {
    int dir[4][2] = {{-1,0},{0,1}, {1,0}, {0,-1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>,int>> Q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    Q.push(make_pair(make_pair(i,j),0));
                    visited[i][j] = 1;
                    grid[i][j] = 0;
                }
            }
        }

        while(!Q.empty()){
            int cur_row = Q.front().first.first;
            int cur_col = Q.front().first.second;
            int cur_level = Q.front().second;

            Q.pop();

            for(int k=0;k<4;k++){
                int i = cur_row + dir[k][0];
                int j = cur_col + dir[k][1];

                if(i<0 || j<0 || i>=n || j>=m || visited[i][j]==1 || grid[i][j]==-1){
                    continue;
                }
                visited[i][j] = 1;
                grid[i][j] = cur_level + 1;
                Q.push(make_pair(make_pair(i,j),cur_level+1));
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==INT_MAX){
                    grid[i][j] = -1;
                }
            }
        }
    }
};
