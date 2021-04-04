class MyCircularQueue {
private:
    vector<int> circularQueue;
    int k, start=0, end=0;
    
public:
    MyCircularQueue(int k) {
        this->k = k;
        this->circularQueue = vector<int>(k, -1);
    }
    
    bool enQueue(int value) {
        if(!isFull()) {
            circularQueue[end%k] = value;
		    end++;
            return true;
        }
		return false;
    }
    
    bool deQueue() {
        if(!isEmpty()) {
            circularQueue[start%k] = -1;
            start++;
            return true;    
        }
		return false;
    }
    
    int Front() {
        return circularQueue[start%k];
    }
    
    int Rear() {
        return circularQueue[(end-1)%k];
    }
    
    bool isEmpty() {
        return (start == end);
    }
    
    bool isFull() {
        return (end-start == k);
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