class SeatManager {
// Easy
public:
    int count;
    priority_queue<int> pq;
    SeatManager(int n) {
        count = 1;
    }
    
    int reserve() {
        int ans = 0;
        if (!pq.empty() && pq.top() < count) {
            ans = pq.top() * -1;
            pq.pop();
        } else {
            ans = count; 
            count ++;
        }

        return ans;
    }
    
    void unreserve(int seatNumber) {
        pq.push(-seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
