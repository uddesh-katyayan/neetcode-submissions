class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur_unique = -200;
        int ins_pos = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=cur_unique){
                nums[ins_pos] = nums[i];
                cur_unique = nums[ins_pos];
                ins_pos++;
            }
        }
        return ins_pos;
    }
};