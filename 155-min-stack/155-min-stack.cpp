class MinStack {
public:
    stack<int>s;
    stack<int>aux;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(aux.size() == 0 || aux.top() >= val){
            aux.push(val);
        }
        return;
    }
    
    void pop() {
        if(s.size() == 0)
            return;
        int ans = s.top();
        s.pop();
        if(ans == aux.top()){
            aux.pop();
        }
        return;
    }
    
    int top() {
        // if(s.size() == 0)
        //     return -1;
        return s.top();
    }
    
    int getMin() {
        return aux.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */