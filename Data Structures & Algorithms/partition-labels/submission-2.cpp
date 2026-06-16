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
            if(end==start){
                ans.push_back(end - start + 1);
            } else{
                int k = i + 1;
                while(k<=end && k<n){
                    int cur_end = last[s[k]-'a'];
                    end = max(end, cur_end);
                    cout << s[i] << " end: " << end << " cur_end: " << cur_end << " k: " << k << endl;
                    if(k == end){
                        ans.push_back(end-start+1);
                        break;
                    } 
                    k++;
                }
                i = end;
            }
        }
        return ans;
    }
};
