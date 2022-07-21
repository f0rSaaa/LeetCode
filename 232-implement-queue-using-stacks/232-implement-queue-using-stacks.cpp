class MyQueue {
public:
    stack<int>s;
    stack<int>auxS;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s.empty()){
            int i = s.top();
            s.pop();
            auxS.push(i);
        }
        auxS.push(x);
        while(!auxS.empty()){
            int i = auxS.top();
            auxS.pop();
            s.push(i);
        }
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