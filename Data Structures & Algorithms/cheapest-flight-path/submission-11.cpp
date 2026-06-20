class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for(int i=0;i<=k;i++){
            vector<int> temp = dist;
            for(auto flight: flights){
                int s = flight[0];
                int d = flight[1];
                int p = flight[2];
                if(dist[s]==INT_MAX){
                    continue;
                }
                temp[d] = min(temp[d], dist[s]+p);
            }
            for(int& d: temp){
                cout << d << "\t";
            }
            cout << endl;
            dist = temp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
