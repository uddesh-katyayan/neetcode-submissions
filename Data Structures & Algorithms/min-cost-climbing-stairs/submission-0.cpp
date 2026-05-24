class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> reach(n+1, 0);
        for(int i=2;i<=n;i++){
            reach[i] = min(cost[i-2]+reach[i-2], cost[i-1]+reach[i-1]);
            cout<<reach[i]<<endl;
        }
        return reach[n];
    }
};
/**
reach[i] = min(cost[i-2] + reach[i-2], cost[i-1] + reach[i-1])
reach[0] = 0;
reach[1] = 0;
minimum cost to reach the top of stairs = min(reach[n], reach[n+1])
*/
// 0 0 1 2 