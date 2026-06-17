class MyCircularQueue {
    int push_ind;
    int pop_ind;
    int num_elements;
    vector<int> space;
    int k;
public:
    MyCircularQueue(int k) {
        push_ind = 0;
        pop_ind = 0;
        num_elements = 0;
        space.resize(k);
        this->k = k;
    }
    
    bool enQueue(int value) {
        if(num_elements==k)
            return false;
        space[push_ind] = value;
        push_ind = (push_ind + 1)%k;
        num_elements++;
        print();
        return true;
    }
    
    bool deQueue() {
        if(num_elements==0)
            return false;
        pop_ind = (pop_ind + 1)%k;
        num_elements--;
        print();
        return true;
    }
    
    int Front() {
        if(num_elements==0)
            return -1;
        return space[pop_ind];
    }
    
    int Rear() {
        if(num_elements==0)
            return -1;
        return space[(push_ind+k-1)%k];
    }
    
    bool isEmpty() {
        return num_elements == 0;
    }
    
    bool isFull() {
        return num_elements == k;
    }

    void print(){
        cout << "Push ind: " << push_ind << endl;
        cout << "Pop ind: " << pop_ind << endl;
        cout << "Total: " << num_elements << endl;
        cout << endl;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */