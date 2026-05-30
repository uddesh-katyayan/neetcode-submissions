class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = -1;
        for(int i=0;i<piles.size();i++){
            mx = max(mx, piles[i]);
        }
        int l = 1;
        int r = mx;
        int ans = INT_MAX;
        while(l<=r){
            int mid = r + (l-r)/2;
            int time_taken = timeTaken(piles, mid);
            if (time_taken <= h){
                // True case, reduce the right
                r = mid - 1;
                ans = min(ans, mid);
            }
            else if(time_taken > h){
                l = mid + 1;
            }
        }
        return ans;
    }
private:
    int timeTaken(vector<int> piles, int k){
        int time = 0;
        for(int i=0;i<piles.size();i++){
            time += (piles[i]%k==0) ? piles[i]/k : piles[i]/k + 1;
        }
        return time;
    }
};
