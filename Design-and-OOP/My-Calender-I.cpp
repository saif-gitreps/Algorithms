class MyCalendar {
// Worked.
public:
    map<int, int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = mp.upper_bound(start);

        if(it == mp.end()){
            mp[end] = start;
            return true;
        }

        if(start < it -> first && start >= it -> second){
            return false;
        } 
        else if(start < it -> second && start < it -> first && (end > it -> first || end > it -> second)){
            return false;
        }

        mp[end] = start;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */



// similar soln but here the condition checking is reduced and it logically works, the conditions in my soln 
// is complicated and I overthought it.
 map<int,int>events;
    MyCalendar() {   
    }
    bool book(int start, int end) {
        auto next = events.upper_bound(start);
        if(next != events.end() &&   (*next).second < end)return false;
        events.insert({end,start});
        return true;
    }
