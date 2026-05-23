class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> rightMax = vector<int>(n,0);
        for (int i=n-2;i>=0;i--){
            rightMax[i] = max(rightMax[i+1], prices[i+1]);
        }
        int max_profit = 0;
        for(int i=0;i<n;i++){
            max_profit = max(max_profit, rightMax[i] - prices[i]);
        }
        return max_profit;
    }
};
