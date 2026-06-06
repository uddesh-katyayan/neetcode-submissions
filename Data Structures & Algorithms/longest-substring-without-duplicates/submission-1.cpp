class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> seen;
        int max_len = 0;
        int cur_len = 0;
        int left = 0;
        for(int right=0;right<n;right++){
            int cur_char = s[right];
            if(seen.count(cur_char)){
                max_len = max(max_len, cur_len);
                int next_left = seen[cur_char] + 1;
                while(left <= right){
                    if(left==next_left){
                        cur_len = right-left+1;
                        seen[cur_char] = right;
                        break;
                    }
                    seen.erase(s[left++]);
                }
            }else{
                cur_len++;
                seen[cur_char] =  right;
            }
        }
        max_len = max(max_len, n-left);
        return max_len;
    }
};
