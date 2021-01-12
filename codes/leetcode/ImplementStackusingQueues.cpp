class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int size = q.size();
        while (size > 1) {
            int element = q.front();
            q.pop();
            q.push(element);
            size--;
        }
    }
    
    int pop() {
        int element = q.front();
        q.pop();
        return element;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};