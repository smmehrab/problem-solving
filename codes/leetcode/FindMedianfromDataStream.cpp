/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
class MedianFinder {
    
private:
    priority_queue<double> maxHeap; 
	priority_queue<double,vector<double>,greater<double> > minHeap; 
	double median=-1;
    
public:
    MedianFinder() {

    }
    
    void addNum(int element) {
        if (maxHeap.size()>minHeap.size()) { 
			if (element<median) { 
				minHeap.push(maxHeap.top()); 
				maxHeap.pop(); 
				maxHeap.push(element); 
			} 
			else minHeap.push(element); 
			median = (maxHeap.top() + minHeap.top())/2.0; 
		} 

		else if(maxHeap.size()<minHeap.size()) { 
			if (element>median) { 
				maxHeap.push(minHeap.top()); 
				minHeap.pop(); 
				minHeap.push(element); 
			} 
			else maxHeap.push(element); 
			median = (maxHeap.top() + minHeap.top())/2.0; 
		} 

		else { 
			if (element<median) { 
				maxHeap.push(element); 
				median = maxHeap.top(); 
			} 
			else { 
				minHeap.push(element); 
				median = minHeap.top(); 
			} 
		} 
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */