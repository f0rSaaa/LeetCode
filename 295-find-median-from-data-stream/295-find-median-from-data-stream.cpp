class MedianFinder {
public:
    
    priority_queue<int>maxH;        //max heap will contain 1st half which will contain small values as we need the max value from that 
    priority_queue<int, vector<int>, greater<int>>minH; //min heap will contain the 2nd half which will contain the rest value as we need min value from that
    
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(maxH.size() == 0 || maxH.top() > num){
            maxH.push(num);
        } else {
            minH.push(num);
        }
        balanceHeap();
    }
    void balanceHeap(){
        if(maxH.size() > minH.size() +1){
            int x = maxH.top();
            maxH.pop();
            minH.push(x);
        } else if(minH.size() > maxH.size() +1){
            int y = minH.top();
            minH.pop();
            maxH.push(y);
        }
    }
    
    double findMedian() {
        if(maxH.size() == minH.size()){
            return (maxH.top() + minH.top()) / 2.0;
        } else if(maxH.size() > minH.size()){
            return maxH.top() / 1.0;
        } else {
            return minH.top() / 1.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */