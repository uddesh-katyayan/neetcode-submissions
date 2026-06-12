class Solution {
public:
    bool validPalindrome(string s) {
        return valid(s, 1);
    }
private:
    bool valid(string s, int k){
        int n = s.size();
        int l = 0;
        int r = n-1;
        int del = 0;
        bool status = true;
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
                continue;
            }
            if(del == k){
                return false;
            }
            // delete/shift left
            bool status_left = false;
            bool status_right = false;
            if(l+1<=r){
                if(s[l+1]==s[r]){
                    del++;
                    status_left = valid(s.substr(l+1, r-l), 0);
                    cout << "status_left: " << status_left << endl;
                }
            }
            if(r-1>=l){
                if(s[r-1]==s[l]){
                    del++;
                    status_right = valid(s.substr(l, r-l), 0);
                    cout << "status_right: " << status_right << endl;
                }
            }
            if(status_left || status_right){
                status = true;
                break;
            }
            return false;
        }
        return status;
    }
};