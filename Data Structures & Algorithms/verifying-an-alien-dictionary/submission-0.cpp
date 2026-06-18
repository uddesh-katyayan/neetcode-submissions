class Solution {
    unordered_map<char, int> ord;
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.size();i++){
            ord[order[i]] = i;
        }
        for(int i=1;i<words.size();i++){
            bool status = inOrder(words[i-1], words[i]);
            if(!status){
                return false;
            }
        }
        return true;
    }
private:
    bool inOrder(string s1, string s2){
        int n = min(s1.size(), s2.size());
        for(int i=0;i<n;i++){
            if(ord[s1[i]]>ord[s2[i]]){
                return false;
            } else if(ord[s1[i]]<ord[s2[i]]) {
                return true;
            }
        }
        if(s1.substr(0, n) == s2)
            return false;
        return true;
    }
};