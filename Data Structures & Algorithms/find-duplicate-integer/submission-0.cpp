class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        for(int i=0;i<nums.size();i++){
            int num = abs(nums[i]);
            int ind = num - 1;
            int ind_value = nums[ind];
            if(ind_value < 0){
                ans = num;
            }
            else{
                nums[ind] = -nums[ind];
            }
        }
        for(int i=0;i<nums.size();i++){
            nums[i] = abs(nums[i]);
        }
        return ans;
    }
};
