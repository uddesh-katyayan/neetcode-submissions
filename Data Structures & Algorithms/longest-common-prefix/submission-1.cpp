class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        int ind = 0;
        char cur_char;
        string common = "";
        while(true){
            if(strs[0].size()<=ind){
                break;
            }
            cur_char = strs[0][ind];
            bool status = true;
            for(int i=1;i<strs.size();i++){
                if(strs[i][ind]!=cur_char){
                    status = false;
                }
            }
            if(!status){
                break;
            }
            common += cur_char;
            ind++;
        }   
        return common;
    }
};