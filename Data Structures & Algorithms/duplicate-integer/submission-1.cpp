class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> nums_set;
        for(int i=0;i<nums.size();i++){
            if(nums_set.find(nums[i])!=nums_set.end())
                return true;
            nums_set.insert(nums[i]);
        }
        return false;
    }
};