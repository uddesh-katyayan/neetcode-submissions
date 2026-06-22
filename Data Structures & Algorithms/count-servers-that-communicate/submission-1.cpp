class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<int, int> rows, cols;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        int ser = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(rows[i]>1 || cols[j]>1)  
                        ser++;
                }
            }
        }
        return ser;
    }
};