class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int n = s.size();
        int j = n-1;
        while(i<j){
            while(i<j && !isalnum(s[i])){
                i++;
            }
            // cout<<i<<" "<<s[i]<<endl;
            while(i<j && !isalnum(s[j])){
                j--;
            }
            // cout<<j<<" "<<s[j]<<endl;
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
