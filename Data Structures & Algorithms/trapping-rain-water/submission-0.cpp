class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n,0), right_max(n,0);
        int left = 0;
        for(int i=0;i<n;i++){
            left_max[i] = left;
            left = max(left, height[i]);
        }
        int right = 0;
        for(int i=n-1;i>=0;i--){
            right_max[i] = right;
            right = max(right, height[i]);
        }
        int water_trapped = 0;
        for(int i=0;i<n;i++){
            int max_water = min(left_max[i], right_max[i]);
            water_trapped += (max_water - height[i]) > 0 ?
                (max_water - height[i]) : 0;
        }
        return water_trapped;
    }
};
