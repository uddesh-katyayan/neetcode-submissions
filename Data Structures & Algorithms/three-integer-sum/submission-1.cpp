class Solution {
public:
    vector<vector<int>> twoSum(vector<int> nums, int target, int start){
        int i = start;
        int j = nums.size() - 1;
        vector<vector<int>> ans;
        while(i<j){
            if(nums[i]+nums[j]==target){
                ans.push_back({i,j});
                i++;
                j--;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++){
            int target = -nums[i];
            vector<vector<int>> ans = twoSum(nums, target, i+1);
            for(int j=0;j<ans.size();j++){
                res.insert({nums[i], nums[ans[j][0]], nums[ans[j][1]]});
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
