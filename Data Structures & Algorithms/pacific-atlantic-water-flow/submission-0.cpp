class Solution {
public:
    int dir[4][2] = {{-1, 0}, {0,1}, {1,0}, {0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        if(n==0){
            return{{}};
        }
        int m = heights[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        // For pacific
        for(int j=0;j<m;j++){
            if(visited[0][j] == 0)
                dfs(heights, visited, 0, j, n, m);
        }
        for(int i=1;i<n;i++){
            if(visited[i][0] == 0)
                dfs(heights, visited, i, 0, n, m);
        }
        vector<vector<int>> visited_2(n, vector<int>(m, 0));
        //For atlantic
        for(int j=0;j<m;j++){
            if(visited_2[n-1][j] == 0)
                dfs(heights, visited_2, n-1, j, n, m);
        }
        for(int i=0;i<n-1;i++){
            if(visited_2[i][m-1] == 0)
                dfs(heights, visited_2, i, m-1, n, m);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==1 && visited_2[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
private: 
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int i, int j, int n, int m){
        visited[i][j] = 1;
        for(int k=0;k<4;k++){
            int cur_height = heights[i][j];
            int new_i = i+dir[k][0];
            int new_j = j+dir[k][1];
            if(!(new_i<0 || new_j < 0 || new_i>=n || new_j >=m)){
                int new_height = heights[new_i][new_j];
                if((new_height>=cur_height) && visited[new_i][new_j]==0){
                    dfs(heights, visited, new_i, new_j, n, m);
                }
            }
        }
    }
};
