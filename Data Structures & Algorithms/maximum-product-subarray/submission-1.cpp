class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProduct = 1;
        int maxProduct = 1;
        int mx = INT_MIN;
        for(int i=0;i<nums.size();i++){
            int prod1 = minProduct * nums[i];
            int prod2 = maxProduct * nums[i];
            if(nums[i]==0){
                minProduct = 1;
                maxProduct = 1;
                mx = max(mx, 0);
                continue;
            }
            if(prod1 < 0 && prod2 < 0){
                minProduct = min(prod1, prod2);
                mx = max(mx, max(prod1, prod2));
                maxProduct = 1;
            } else if (prod1>0 && prod2>0){
                maxProduct = max(prod1, prod2);
                mx = max(mx, max(prod1, prod2));
                minProduct = 1;
            } else if(prod1>0){
                minProduct = prod2;
                maxProduct = prod1;
                mx = max(mx, prod1);
            } else{
                minProduct = prod1;
                maxProduct = prod2;
                mx = max(mx, prod2);
            }
        }
        return mx;
    }
};
