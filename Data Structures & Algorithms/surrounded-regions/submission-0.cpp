class Solution {
public:
    int dir[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    void solve(vector<vector<char>>& board) {
        //traverse the sides and do a dfs
        for(int j=0;j<board[0].size();j++){
            dfs(board, 0, j);
            if(board.size()>1){
                dfs(board, board.size()-1, j);
            }
        }
        for(int i=1;i<board.size()-1;i++){
            dfs(board, i, 0);
            if(board[0].size()>1){
                dfs(board, i, board[0].size()-1);
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '*'){
                    board[i][j] = 'O';
                }
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i<0 || j<0 || i>= board.size() || j>=board[0].size()
        || board[i][j] == 'X' || board[i][j] == '*'){
            return;
        }
        board[i][j] = '*';
        for(int k=0;k<4;k++){
            dfs(board, i+dir[k][0], j+dir[k][1]);
        }
    }
};
