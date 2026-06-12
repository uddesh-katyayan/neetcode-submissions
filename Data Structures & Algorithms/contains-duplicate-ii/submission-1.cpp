class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        unordered_set<int> present;
        while(r<n && r<=k){
            if(present.count(nums[r])){
                return true;
            }
            present.insert(nums[r++]);
        }
        while(r<n){
            cout<< r<< endl;
            present.erase(nums[l]);
            l++;
            if(present.count(nums[r])){
                return true;
            }
            present.insert(nums[r++]);
        }
        return false;
    }
};