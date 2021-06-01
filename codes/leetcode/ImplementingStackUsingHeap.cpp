/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<bits/stdc++.h> 
using namespace std; 

class Stack{ 
private:
	int key; 
	priority_queue<pair<int, int> > heap; 

public: 
	Stack() {
        this->key = 0;
    }

	void push(int n) { 
        key++; 
        heap.push({key, n}); 
    } 

	void pop() { 
        if(heap.empty()) cout<< "Heap is empty!" << endl;  
        key--; 
        heap.pop();
    } 

	int top() { 
        pair<int, int> topPair = heap.top(); 
        return topPair.second; 
    } 

	bool isEmpty() { 
        return heap.empty(); 
    } 
}; 

int main() { 
	Stack* s = new Stack();

	s->push(10); 
	s->push(20); 
	s->push(30); 
	
    while(!s->isEmpty()) { 
		cout << s->top() << endl; 
		s->pop(); 
	}
    
    return 0; 
} 