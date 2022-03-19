class FreqStack {
public:
    
    // https://leetcode.com/problems/maximum-frequency-stack/discuss/1862055/C%2B%2B-oror-Explained-With-Algorithm-oror-HashMap
    
    unordered_map<int, int>fMap;
    unordered_map<int, stack<int>>sMap;
    int maxF = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        int freq = fMap[val]+1;
        fMap[val] = freq;
        maxF = max(freq, maxF);
        sMap[freq].push(val);
    }
    
    int pop() {
        int top = sMap[maxF].top();
        sMap[maxF].pop();
        fMap[top]--;
        if(sMap[maxF].size() == 0){
            maxF--;
        }
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */