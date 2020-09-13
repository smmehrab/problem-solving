#include<bits/stdc++.h> 
using namespace std; 

void findMedians() {
	priority_queue<double> maxHeap; 
	priority_queue<double,vector<double>,greater<double> > minHeap; 
	double median=-1, element; 

	for (int i=0; ; i++) { 
		cin >> element; 

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

		cout << median << endl; 
	} 
} 

int main() {     
	findMedians(); 
	return 0; 
} 