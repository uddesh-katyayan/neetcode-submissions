class cmp {
public:
    bool operator()(pair<int, vector<int>>& a,
                    pair<int, vector<int>>& b) {
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, cmp> max_heap;
        for(int i=0;i<points.size();i++){
            int dist = distance(points[i]);
            if(max_heap.size()<k){
                max_heap.push(make_pair(dist, points[i]));
            }
            else{
                if(max_heap.top().first > dist){
                    max_heap.pop();
                    max_heap.push(make_pair(dist, points[i]));
                }
            }
        }
        vector<vector<int>> ans;
        while(!max_heap.empty()){
            cout << max_heap.top().first << " (" <<  max_heap.top().second[0] <<
                "," << max_heap.top().second[1] << ")" << endl;
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return ans;
    }
private:
    int distance(vector<int> a){
        return (a[0]*a[0] + a[1]*a[1]);
    }
};
