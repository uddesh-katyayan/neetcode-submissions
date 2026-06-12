class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        prefix_sum.resize(n+1, vector<int>(m+1,0));
        // for(int i=0;i<n;i++){
        //     prefix_sum[i].resize(m);
        // }
        // int sum = 0;
        // prefix_sum[0][0] = matrix[0][0];
        // for(int i=1;i<m;i++){
        //     prefix_sum[0][i] = prefix_sum[0][i-1] + matrix[0][i];
        // }
        // for(int i=1;i<n;i++){
        //     prefix_sum[i][0] = prefix_sum[i-1][0] + matrix[i][0];
        // }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                prefix_sum[i][j] = matrix[i-1][j-1] + prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        // int total = prefix_sum[r2][c2];
        // if(r1-1>=0){
        //     total -= prefix_sum[r1-1][c2];
        // }
        // if(c1-1>=0){
        //     total -= prefix_sum[r2][c1-1];
        // }
        // if(r1-1 >=0 && c1-1>=0){
        //     total += prefix_sum[r1-1][c1-1];
        // }
        // return total;
        return prefix_sum[r2+1][c2+1] - prefix_sum[r1][c2+1] - prefix_sum[r2+1][c1] + prefix_sum[r1][c1];
    }
private:
    vector<vector<int>> prefix_sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */