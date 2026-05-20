class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        int i = 0;
        for(auto &p: freq){
            if(i<k){
                min_heap.push(make_pair(p.second, p.first));
            }
            else{
                pair<int, int> min_v = min_heap.top();
                if(p.second > min_v.first){
                    min_heap.pop();
                    min_heap.push(make_pair(p.second, p.first));
                }
            }
            i++;
        }
        vector<int> ans;
        while(!min_heap.empty()){
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
};
