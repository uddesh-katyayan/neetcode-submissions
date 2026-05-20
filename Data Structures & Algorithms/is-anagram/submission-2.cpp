class Solution {
public:
    bool isAnagram(string s, string t) {
        multiset<char> s_set;
        multiset<char> t_set;
        int n = s.size();
        if (t.size()!=n)
            return false;
        for(int i=0;i<n;i++){
            s_set.insert(s[i]);
            t_set.insert(t[i]);
        }
        int i=0;
        auto s_it = s_set.begin();
        auto t_it = t_set.begin();
        while(i<n){
            if (*s_it != *t_it)
                return false;
            s_it++;
            t_it++;
            i++;
        }
        return true;
    }
};
