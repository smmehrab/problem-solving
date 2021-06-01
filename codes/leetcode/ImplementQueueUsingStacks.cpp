/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
class MyQueue {
private:
    stack<int> stack1;
    stack<int> stack2;
    
    int popStack2(){
        int poppedElement = stack2.top();
        stack2.pop();
        return poppedElement;
    }
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!stack2.empty()) return popStack2();
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        return stack2.empty() ? -1 : popStack2();
    }
    
    /** Get the front element. */
    int peek() {
        if(!stack2.empty()) return stack2.top();
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
         }
        return stack2.empty() ? -1 : stack2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */