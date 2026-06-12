class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        merge(word1, word2, 0, 0, ans);
        return ans;
    }
private:
    void merge(string s1, string s2, int l1, int l2, string& ans){
        if(l1>= s1.size() && l2 >= s2.size()){
            return;
        }
        else if(l1>=s1.size()){
            ans = ans + s2.substr(l2);
            return;
        } else if(l2>=s2.size()){
            ans = ans + s1.substr(l1);
            return;
        }
        ans += s1[l1];
        ans += s2[l2];
        merge(s1, s2, l1+1, l2+1, ans);
    }
};