class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads;
        for(string& s: deadends){
            deads.insert(s);
        }
        queue<pair<string, int>> Q;
        if(deads.count("0000"))
            return -1;
        Q.push({"0000", 0});
        unordered_set<string> visited;
        visited.insert("0000");
        while(!Q.empty()){
            auto [num, turn] = Q.front();
            Q.pop();
            vector<string> nbrs = getNeighbors(num);
            for(string& nbr: nbrs){
                // cout << nbr << "\t";
                if(deads.count(nbr) || visited.count(nbr)){
                    continue;
                }
                if(nbr==target){
                    return turn + 1;
                }
                Q.push({nbr, turn+1});
                visited.insert(nbr);
            }
            // cout << endl;
            // break;
        }
        return -1;
    }
private:
    vector<string> getNeighbors(string str){
        vector<string> ans;
        for(int i=0;i<4;i++){
            int dig = str[i] - '0';
            int next = (dig + 1)%10;
            int prev = (dig - 1)%10;
            prev = prev == -1 ? 9:prev;
            // cout << next << " " << prev << endl;
            string s1 = str;
            s1[i] = '0' + next;
            ans.push_back(s1);
            s1[i] = '0' + prev;
            ans.push_back(s1);
        }
        return ans;
    }
};


/**
0198 -> 0199, 0197, 0108, 0188, 0298, 0098, 1198, 9198
*/


