class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i=0;i<nums.size();i++){
            int left = target - nums[i];
            if (hash.find(left)!=hash.end()){
                vector<int> ans = {hash[left], i};
                return ans;
            }
            else{
                if(hash.find(nums[i])==hash.end())
                    hash[nums[i]] = i;
            }
        }
    }
};
