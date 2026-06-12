class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> tracker;
        for(int i=0;i<n;i++){
            if(i>k){
                tracker.erase(nums[i-k-1]);
            }
            if(tracker.count(nums[i])){
                return true;
            }
            tracker.insert(nums[i]);
        }
        return false;
    }
};