class Solution {
public:
    int dir[4][2] = {{-1,0}, {1,0}, {0,1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> tracker(n, vector<int>(m, INT_MAX));
        // BFS from all the places where 2
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    //BFS with new visited marker
                    set<string> visited;
                    queue<vector<int>> Q;
                    Q.push({i,j,0});
                    visited.insert(to_string(i)+'-'+to_string(j));
                    while(!Q.empty()){
                        vector<int> t = Q.front();
                        int ii = t[0];
                        int jj = t[1];
                        // cout << ii << " " << jj <<endl;
                        int days = t[2];
                        tracker[ii][jj] = min(tracker[ii][jj], days);
                        for(int k=0;k<4;k++){
                            int new_ii = ii+dir[k][0];
                            int new_jj = jj+dir[k][1];
                            // cout << "----New direction----" <<endl;
                            // cout<< new_ii << " " << new_jj << endl;
                            if(!(new_ii<0 || new_jj<0 || new_ii>=n || new_jj>=m)){
                                // cout << "entered inside loop" <<endl;
                                if(grid[new_ii][new_jj]!=1)
                                    continue;
                                string visitor_key = to_string(new_ii)+'-'+to_string(new_jj);
                                if(visited.find(visitor_key)==visited.end()){
                                    //Not visited yet
                                    // cout << "Not visited yet" <<endl;
                                    Q.push({new_ii, new_jj, days+1});
                                    visited.insert(visitor_key);
                                }
                            }
                        }
                        Q.pop();
                    }

                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout << tracker[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    
        int min_days = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(tracker[i][j]==INT_MAX){
                        return -1;
                    }
                    // cout << i << " " << j << endl;
                    // cout << tracker[i][j]<<endl;
                    min_days = max(tracker[i][j], min_days);
                }
            }
        }
        return min_days;
    }
};
