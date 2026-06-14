class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>, less<int>> max_heap;
    int diff;
public:
    MedianFinder() {
        diff = 0;
    }
    
    void addNum(int num) {
        if(max_heap.empty() && min_heap.empty()){
            max_heap.push(num);
            diff = 1;
        } else if(min_heap.empty()){
            int l = max_heap.top();
            if(num<l){
                max_heap.pop();
                max_heap.push(num);
                min_heap.push(l);
            } else{
                min_heap.push(num);
            }
            diff = 0;
        } else{
            int l = max_heap.top();
            int r = min_heap.top();
            if(num<=l){
                if(diff == 0){
                    max_heap.push(num);
                    diff = 1;
                } else{
                    max_heap.pop();
                    max_heap.push(num);
                    min_heap.push(l);
                    diff = 0;
                }
            } else if(num>=r){
                if(diff == 0){
                    min_heap.pop();
                    max_heap.push(r);
                    min_heap.push(num);
                    diff = 1;
                } else{
                    min_heap.push(num);
                    diff = 0;
                }
            } else{
                if(diff == 0){
                    max_heap.push(num);
                    diff = 1;
                } else{
                    max_heap.pop();
                    max_heap.push(num);
                    min_heap.push(l);
                    diff = 0;
                }
            }
        }
    }
    
    double findMedian() {
        if(diff==0){
            return (max_heap.top() + min_heap.top()) / 2.0;
        }else{
            return max_heap.top();
        }
    }
};
