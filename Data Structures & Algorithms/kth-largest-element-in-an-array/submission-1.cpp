class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap_k;
        for(int i=0;i<nums.size();i++){
            if(min_heap_k.size() < k){
                min_heap_k.push(nums[i]);
            }
            else{
                if(min_heap_k.top() < nums[i]){
                    min_heap_k.pop();
                    min_heap_k.push(nums[i]);
                }
            }
        }
        if(!min_heap_k.empty()){
            return min_heap_k.top();
        }
        return -1;
    }
};
