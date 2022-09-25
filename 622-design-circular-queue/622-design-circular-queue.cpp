class MyCircularQueue {
    int k;
    queue<int> q;
public:
    MyCircularQueue(int k) {
        this->k = k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        q.push(value);
        return true;
    }
    
    bool deQueue() {
        if(q.empty()){
            return false;
        }
        q.pop();
        return true;
    }
    
    int Front() {
        if(q.empty()){
            return -1;
        }
        return q.front();
    }
    
    int Rear() {
        if(q.empty()){
            return -1;
        }
        int n = q.size();
        for(int i=0;i<n-1;i++){
            q.push(q.front());
            q.pop();
        }
        int x = q.front();
        q.push(q.front());
        q.pop();
        return x;
    }
    
    bool isEmpty() {
        return q.empty();
    }
    
    bool isFull() {
        if(q.size()==k)
            return true;
        return false;
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