class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix_sum(n+1, 0);
        for(int i=0;i<n;i++){
            prefix_sum[i+1] = prefix_sum[i] + nums[i];
        }
        unordered_map<int, int> occ;
        int ans = 0;
        for(int i=n;i>=0;i--){
            int a = prefix_sum[i] + k;
            // int b = prefix_sum[i] - k;
            ans += occ[a];
            // if(a!=b){
            //     ans += occ[b];
            // }
            occ[prefix_sum[i]]++;
        }
        return ans;
    }
};