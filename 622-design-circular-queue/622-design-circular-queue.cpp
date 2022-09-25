class MyCircularQueue {
    int k;
    vector<int> q;
public:
    MyCircularQueue(int k) {
        this->k = k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        
        q.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        
        for(int i=0;i<q.size()-1;i++){
            q[i] = q[i+1];
        }
        q.pop_back();
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return q[0];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return q[q.size()-1];
    }
    
    bool isEmpty() {
        return q.size()==0;
    }
    
    bool isFull() {
        return q.size()==k;
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