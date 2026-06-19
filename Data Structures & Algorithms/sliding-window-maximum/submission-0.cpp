class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> ordered;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(i<k){
                ordered[nums[i]]++;
                if(i==k-1){
                    ans.push_back(prev(ordered.end())->first);
                }
                continue;
            }
            ordered[nums[i]]++;
            ordered[nums[i-k]]--;
            if(ordered[nums[i-k]]==0)
                ordered.erase(nums[i-k]);
            ans.push_back(prev(ordered.end())->first);
        }
        return ans;
    }
};
