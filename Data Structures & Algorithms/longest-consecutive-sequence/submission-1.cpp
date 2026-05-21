class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hash;
        int longest = 0;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]] = 1;
        }
        for(int i=0;i<nums.size();i++){
            if(hash[nums[i]-1]==0){
                //not found
                // count consecutive numbers
                int len = 1;
                int num = nums[i];
                while(true){
                    if (hash[++num] != 0){
                        len++;
                    }
                    else{
                        break;
                    }
                }
                longest = len > longest ? len : longest;
            }

        }
        return longest;
    }
};
