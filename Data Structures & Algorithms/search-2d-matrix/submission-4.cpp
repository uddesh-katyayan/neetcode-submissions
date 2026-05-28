class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int N = n*m;
        int left = 0;
        int right = N-1;
        while(left<=right){
            int mid = right + (left - right) / 2;
            pair<int, int> ind = get2Dindex(mid, n, m);
            int i = ind.first;
            int j = ind.second;
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return false;
    }
private:
    pair<int, int> get2Dindex(int k, int n, int m){
        int i = max(0,k/n);
        int j = max(0,k%n);
        return make_pair(i,j);
    } 
};
