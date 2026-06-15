class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int mx_len = 1;
        int dir = 0;
        int cur_len = 1;
        for(int i=1;i<n;i++){
            if(dir==0){
                if(arr[i]<arr[i-1]){
                    dir = -1;
                    cur_len++;
                } else if(arr[i]>arr[i-1]){
                    dir = 1;
                    cur_len++;
                }
            }
            else if(dir==1){
                if(arr[i]>=arr[i-1]){
                    cout << "cur len: " << cur_len << endl;
                    mx_len = max(cur_len, mx_len);
                    if(arr[i]>arr[i-1]){
                        cur_len = 2;
                        dir = 1;
                    } else{
                        cur_len = 1;
                        dir = 0;
                    }
                } else {
                    cur_len++;
                    dir = -1;
                }
            } else {
                if(arr[i]<=arr[i-1]){
                    mx_len = max(cur_len, mx_len);
                    if(arr[i]<arr[i-1]){
                        cur_len = 2;
                        dir = -1;
                    } else{
                        cur_len = 1;
                        dir = 0;
                    }
                } else {
                    cur_len++;
                    dir = 1;
                }
            }
            cout << "char: " << arr[i] << " cur len: " << cur_len << endl;
        }
        return max(mx_len, cur_len);
    }
};