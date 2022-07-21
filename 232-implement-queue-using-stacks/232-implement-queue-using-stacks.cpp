class MyQueue {
public:
    stack<int>s;
    MyQueue() {
        
    }
    
    void pushStack(int x){
        if(s.size() == 0){
            s.push(x);
            return;
        }
        int data = s.top();
        s.pop();
        pushStack(x);
        s.push(data);
    }
    
    void push(int x) {
        pushStack(x);
    }
    
    
    int pop() {
        int x = s.top();
        s.pop();
        return x;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();        
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