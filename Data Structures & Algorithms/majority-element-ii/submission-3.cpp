class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = INT_MIN, cand2 = INT_MIN;
        int count1 = 0, count2 = 0;
        for(int i=0;i<nums.size();i++){
            // cout << "Before status" << endl;
            // cout << cand1 << ": " << count1 << endl;
            // cout << cand2 << ": " << count2 << endl;
            if(nums[i]==cand1 || nums[i]==cand2){
                if(nums[i]==cand1)
                    count1++;
                else
                    count2++;
            } else if(count1==0){
                cand1 = nums[i];
                count1 = 1;
            } else if(count2 ==0){
                cand2 = nums[i];
                count2 = 1;
            } else { 
                count1--;
                count2--;
            }
        }
        // Verify if candidates are indeed maj_elements
        int act_count1 = 0;
        int act_count2 = 0;
        for(int& num: nums){
            if(num==cand1 && count1>0){
                act_count1++;
            }
            if(num==cand2 && count2>0){
                act_count2++;
            }
        }
        int maj_limit = nums.size()/3;
        vector<int> ans;
        if(act_count1>maj_limit){
            ans.push_back(cand1);
        }
        if(act_count2>maj_limit && cand2!=cand1){
            ans.push_back(cand2);
        }
        return ans;
    }
};