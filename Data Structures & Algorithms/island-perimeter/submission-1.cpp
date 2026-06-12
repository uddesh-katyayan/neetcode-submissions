class Solution {
public:
    int dir[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> Q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    Q.push(make_pair(i,j));
                    visited[i][j] = true;
                    break;
                }
            }
            if(!Q.empty()){
                    break;
                }
        }
        int perimeter = 0;
        while(!Q.empty()){
            auto [i, j] = Q.front();
            // cout << "Current cell: " << i << " " << j << endl;
            Q.pop();
            int contri = 0;
            for(int k=0;k<4;k++){
                int new_i = i + dir[k][0];
                int new_j = j + dir[k][1];
                // cout << new_i  << " " << new_j << endl;
                if(new_i < 0 || new_j < 0 || new_i >=n || new_j >= m){
                    contri++;
                    continue;
                }
                if(grid[new_i][new_j]==0){
                    contri++;
                    continue;
                }
                if(grid[new_i][new_j]==1 && !visited[new_i][new_j]){
                    // cout << "pushing: " << new_i << " " << new_j << endl;
                    Q.push(make_pair(new_i, new_j));
                    visited[new_i][new_j] = true;
                }
            }
            cout << i << " " << j << "\t" << contri << endl;
            perimeter += contri;
        }
        return perimeter;
    }
};