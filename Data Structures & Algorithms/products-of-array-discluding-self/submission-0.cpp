class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left = vector<int>(n, 1);
        vector<int> right = vector<int>(n, 1);
        vector<int> ans = vector<int>(n, 1);
        for(int i=1;i<n;i++){
            left[i] = nums[i-1]*left[i-1];
        }
        for(int i=n-2;i>=0;i--){
            right[i] = right[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i] = left[i]*right[i];
        }
        return ans;
    }
};
