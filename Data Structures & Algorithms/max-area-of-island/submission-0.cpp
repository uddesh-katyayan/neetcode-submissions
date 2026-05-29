class Solution {
public:
    int directions[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int cur_area = 0;
                    dfs(grid, i, j, cur_area);
                    max_area = max(max_area, cur_area);
                }
            }
        }
        return max_area;
    }
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int& count){
        if(i<0 || j<0 || i>=grid.size() || j>= grid[0].size() || grid[i][j]==0){
            return;
        }
        grid[i][j] = 0;
        count++;
        for(int k=0;k<4;k++){
            dfs(grid, i+directions[k][0], j+directions[k][1], count);
        }
        return;
    }
};
