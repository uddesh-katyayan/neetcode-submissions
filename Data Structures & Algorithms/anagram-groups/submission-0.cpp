class Solution {
public:

    static bool cmp(const pair<int, string>& a, const pair<int, string>& b){
        return a.second < b.second;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<int, string>> processed_data;
        for (int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            processed_data.push_back(make_pair(i, temp));
        }
        sort(processed_data.begin(), processed_data.end(), cmp);
        vector<vector<string>> ans;
        int i = 0;
        while(i<strs.size()){
            vector<string> ana;
            string cur = processed_data[i].second;
            while(i<strs.size() && processed_data[i].second == cur){
                ana.push_back(strs[processed_data[i].first]);
                i++;
            }
            ans.push_back(ana);
        }
        return ans;
    }
};