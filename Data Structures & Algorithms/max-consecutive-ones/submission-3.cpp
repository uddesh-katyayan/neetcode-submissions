class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0;
        int mx_ones = 0;
        for(int& num: nums){
            if(num == 1)
                ones++;
            else{
                mx_ones = max(mx_ones, ones);
                ones = 0;
            }
        }
        return max(mx_ones, ones);
    }
};