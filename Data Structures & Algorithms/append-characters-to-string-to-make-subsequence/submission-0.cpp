class Solution {
public:
    int appendCharacters(string s, string t) {
        int k = 0;
        int matched = 0;
        for(int i=0;i<t.size();i++){
            while(k<s.size()){
                if(t[i]==s[k]){
                    matched++;
                    k++;
                    break;
                }
                k++;
            }
        }
        if(matched == t.size())
            return 0;
        return t.size() - matched;
    }
};