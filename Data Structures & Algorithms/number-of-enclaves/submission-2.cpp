class Solution {
    int dir[4][2] = {{1,0}, {-1, 0}, {0,1}, {0,-1}};
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(i,0,n,m,grid);
            }
            if(grid[i][m-1]==1){
                dfs(i,m-1,n,m,grid);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                dfs(0,j,n,m,grid);
            }
            if(grid[n-1][j]==1){
                dfs(n-1,j,n,m,grid);
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    count++;
            }
        }
        return count;
    }
private:
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid){
        grid[i][j] = 2;
        for(int k=0;k<4;k++){
            int ni = i + dir[k][0];
            int nj = j + dir[k][1];
            if(ni<0 || nj<0 || ni>=n || nj>=m || grid[ni][nj]==0 || grid[ni][nj]==2){
                continue;
            }
            dfs(ni, nj, n, m, grid);
        }
    }
};