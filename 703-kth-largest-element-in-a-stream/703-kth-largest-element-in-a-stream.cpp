class KthLargest {
    priority_queue<int,vector<int>,greater<int>> pq;
    int kth;
public:
    KthLargest(int k, vector<int>& nums) {
        //create a min heap to store elements
        //push elements of nums in minheap until kth
        //if minheap size is less than k, push into the heap
        //if minheap is of size k, then check if currrent element is less or greater than top
        //if top element > val -> don't push val to the heap
        //else -> replace top element of heap with val
        
        kth = k;
        for(auto x : nums){
            add(x);
        }
    }
    
    int add(int val) {
        if(pq.size()<kth){
            pq.push(val);
        }
        else{
            if(pq.top() < val){
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */