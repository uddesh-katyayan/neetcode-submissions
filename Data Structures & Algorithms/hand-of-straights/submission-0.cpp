class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize !=0)
            return false;
        unordered_map<int, int> freqs;
        for(int& num: hand){
            freqs[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for(auto it=freqs.begin(); it!=freqs.end();it++){
            min_heap.push({it->first, it->second});
        }
        int k = groupSize, i = 0, cur_hand = -1;
        vector<pair<int, int>> leftOut(groupSize);
        while(min_heap.size()>=groupSize){
            while(k--){
                auto [val, freq] = min_heap.top();
                // cout << val << ":  " << freq << endl;
                min_heap.pop();
                if(cur_hand==-1){
                    cur_hand = val;
                } else{
                    if(val != cur_hand+1)
                        return false;
                    cur_hand = val;
                }
                if(freq>1){
                    leftOut[i++] = {val, freq-1};
                }
            }
            for(int j=0;j<i;j++){
                // cout << "pushing: " << leftOut[j].first << " with freq: " << leftOut[j].second << endl;
                min_heap.push(leftOut[j]);
            }
            k = groupSize;
            i = 0;
            cur_hand = -1;
        }
        if(!min_heap.empty()){
            return false;
        }
        return true;
    }
};
