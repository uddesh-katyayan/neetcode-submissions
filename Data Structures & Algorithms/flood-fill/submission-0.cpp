class Solution {
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> Q;
        Q.push({sr, sc});
        int starting_pixel = image[sr][sc];
        image[sr][sc] = color;
        visited[sr][sc] = true;
        while(!Q.empty()){
            auto [r, c] = Q.front();
            Q.pop();
            for(int k=0;k<4;k++){
                int n_r = r + dir[k][0];
                int n_c = c + dir[k][1];
                if(n_r<0 || n_c <0 || n_r>=n || n_c >= m)
                    continue;
                if(!visited[n_r][n_c] && image[n_r][n_c] == starting_pixel){
                    image[n_r][n_c] = color;
                    visited[n_r][n_c] = true;
                    Q.push({n_r, n_c});
                }
            }
        }
        return image;
    }
};