class Solution {
    int dir[4][2] = {{-1,0}, {1, 0}, {0,1}, {0,-1}};
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, -1));
        bool marked = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,n);
                    marked = true;
                    break;
                }
            }
            if(marked)
                break;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        queue<pair<pair<int, int>, int>> Q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    Q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }
        while(!Q.empty()){
            auto [ind, lev] = Q.front();
            auto [i, j] = ind;
            Q.pop();
            for(int k=0;k<4;k++){
                int ni = i + dir[k][0];
                int nj = j + dir[k][1];
                if(ni<0 || nj<0 || ni>=n || nj>=n || visited[ni][nj]!=-1){
                    continue;
                }
                if(grid[ni][nj] == 1){
                    return lev;
                }
                Q.push({{ni,nj},lev+1});
                visited[ni][nj] = 1;
            }
        }
        return 0;
    }
private:
    void dfs(int i, int j, vector<vector<int>>& grid, int n){
        grid[i][j] = 2;
        for(int k=0;k<4;k++){
            int ni = i + dir[k][0];
            int nj = j + dir[k][1];
            if(ni<0 || nj<0 || ni>=n || nj>=n || grid[ni][nj]==0 || grid[ni][nj]==2){
                continue;
            }
            dfs(ni, nj, grid, n);
        }
    } 
};