class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int f = m-1;
        int s = n-1;
        int ins = m+n-1;
        while(ins>=0){
            if(f>=0 && s>=0){
                if(nums1[f]>nums2[s]){
                    nums1[ins] = nums1[f];
                    f--;
                } else{
                    nums1[ins] = nums2[s];
                    s--;
                }
            } else if(f>=0){
                nums1[ins] = nums1[f];
                f--;
            } else if(s>=0){
                nums1[ins] = nums2[s];
                s--;
            }
            ins--;
        }
    }
};