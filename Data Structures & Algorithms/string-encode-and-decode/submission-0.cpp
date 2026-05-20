class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(auto &s: strs){
            string subs = to_string(s.size()) + '#' + s;
            encoded += subs;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        int i = 0;
        int n = s.size();
        vector<string> ans;
        while(i<n){
            int j = i;
            int len = 0;
            while(j<n){
                if(s[j]=='#'){
                    break;
                }
                len = len*10 + (s[j] - '0');
                j++;
            }
            string val = s.substr(j+1, len);
            ans.push_back(val);
            i = j + 1 + len;
        }
        return ans;
    }
};
