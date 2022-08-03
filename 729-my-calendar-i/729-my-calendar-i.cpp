class MyCalendar {
public:
    vector<pair<int, int>> booking;
	
    MyCalendar() {
        
    }
    bool book(int start, int end) {
        for (auto it : booking)
        {
            if (max(it.first, start) < min(end, it.second))
            {
                return false;
            } 
        }
        booking.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */