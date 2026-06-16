class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        for(int i=0;i<n;i++){
            last[s[i]-'a'] = i;
        }
        int start = 0;
        int end = 0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            start = i;
            end = last[s[i]-'a'];
            int k = i;
            int cur_end;
            while(k<=end){
                cur_end = last[s[k]-'a'];
                end = max(end, cur_end);
                if(k == end){
                    ans.push_back(end-start+1);
                    break;
                } 
                k++;
            }
            i = end;
        }
        return ans;
    }
};
