class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        int j = n-1;
        int vol = 0;
        while(i<j){
            int width = j-i;
            int temp = min(heights[i], heights[j])*width;
            vol = max(vol, temp);
            if(heights[i]<heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return vol;
    }
};
