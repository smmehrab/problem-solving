class KthLargest {
private:
    priority_queue <int, vector<int>, greater<int> > minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& numbers) {
        this->k = k;
        for(int number : numbers) minHeap.push(number);
    }
    
    int add(int number) {
        minHeap.push(number) ;
        while(minHeap.size()>k) minHeap.pop();
        return minHeap.top() ;
    }
};