/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0;
        int n = mountainArr.length();
        int r = n-1;
        int peak = -1;
        int at_mid, at_mid_r, at_mid_l;
        int i = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            at_mid = mountainArr.get(mid);
            at_mid_l = mid - 1 >=0 ? mountainArr.get(mid-1) : INT_MIN;
            at_mid_r = mid + 1 < n ? mountainArr.get(mid+1) : INT_MIN;

            cout << at_mid_l << " " << at_mid << " " << at_mid_r << " " << endl;

            if(at_mid_l < at_mid && at_mid > at_mid_r) {
                peak = mid;
                break;
            } else if(at_mid_l < at_mid && at_mid < at_mid_r) {
                l = mid + 1;
            } else if(at_mid_l > at_mid && at_mid > at_mid_r) {
                r = mid - 1;
            }
            // i++;
            // if(i==8){
            //     break;
            // }
        }
        cout << "Peak: " << peak << endl;
        // return -1;
        if(peak==-1)
            return -1;
        int at_peak = mountainArr.get(peak);
        if(target==at_peak){
            return peak;
        }
        int left = binary_search(target, 0, peak, 1, mountainArr);
        if(left!=-1)
            return left;
        return binary_search(target, peak+1, n-1, -1, mountainArr);
    }
private:
    int binary_search(int target, int l, int r, int dir,  MountainArray &mountainArr){
        int at_mid;
        while(l<=r){
            int mid = l + (r-l)/2;
            at_mid = mountainArr.get(mid);

            if(at_mid == target) {
                return mid;
            } else if(dir==1){
                if(target<at_mid){
                    r = mid - 1;
                } else{
                    l = mid + 1;
                }
            } else {
                if(target<at_mid){
                    l = mid + 1;
                } else{
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};