class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maj_freq = 0;
        int maj_val;
        for(auto& num: nums){
            if(freq.count(num)){
                freq[num]++;
            }
            else{
                freq[num] = 1;
            }
            if(freq[num]>maj_freq){
                maj_freq = freq[num];
                maj_val = num;
            }
        }
        return maj_val;
    }
};