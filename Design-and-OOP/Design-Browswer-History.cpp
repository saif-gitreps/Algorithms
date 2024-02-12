class BrowserHistory {
// had the same idea as the other guy but diff was i didnt know we have to reset every time we visit something
public:
    string curr;
    stack<string> bac;
    stack<string> ahead;
    BrowserHistory(string homepage) {
        bac.push(homepage);
    }
    void visit(string url) {
        bac.push(url);

        while(!ahead.empty()){
            ahead.pop();
        }
    }
    string back(int steps) {
        while(steps >= 1 && bac.size() > 1){
            steps--;
            ahead.push(bac.top());
            bac.pop();
        }
        return bac.top();
    }
    
    string forward(int steps) {
        while(steps >= 1 && ahead.size() >= 1){
            steps--;
            bac.push(ahead.top());
            ahead.pop();
        }
        return bac.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
