class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string sub = "";
        int len = 0;
        for(int i=0;i<n;i++){
            //Single mirror
            int temp_len = 1;
            string temp_sub = "";
            temp_sub += s[i];
            int k = 1;
            while(true){
                int left = i-k;
                int right = i+k;
                if(left<0 || right>=n){
                    break;
                }
                if(s[left]==s[right]){
                    temp_len+=2;
                    temp_sub = s[left] + temp_sub + s[right];
                }
                else{
                    break;
                }
                k++;
            }
            if(temp_len > len){
                len = temp_len;
                sub = temp_sub;
            }
            if(i+1<n && s[i]==s[i+1]){
                temp_len = 2;
                temp_sub = "";
                temp_sub += s[i];
                temp_sub += s[i+1];
                cout<<temp_sub<<endl;
                int left = i-1;
                int right = i+2;
                while(true){
                    if(left < 0 || right >= n){
                        break;
                    }
                    if(s[left]==s[right]){
                        temp_len+=2;
                        temp_sub = s[left] + temp_sub + s[right];
                    }
                    else{
                        break;
                    }
                    left--;
                    right++;
                }
                if(temp_len > len){
                    len = temp_len;
                    sub = temp_sub;
                }
            }
        }
        return sub;
    }
};
