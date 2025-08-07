
class MinStack {
public:
    map<int, int> mp;
    stack<int> stk;
    MinStack() {
    }
    
    void push(int val) {
        stk.push(val);
        mp[val]++;
    }
    
    void pop() {
        int top = stk.top();
        stk.pop();
        mp[top]--;
        if (mp[top] == 0) {
            mp.erase(top);
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mp.begin()->first;
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


// better soln

class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
	    s1.push(x);
	    if (s2.empty() || x <= getMin())  s2.push(x);	    
    }
    void pop() {
	    if (s1.top() == getMin())  s2.pop();
	    s1.pop();
    }
    int top() {
	    return s1.top();
    }
    int getMin() {
	    return s2.top();
    }
};

// even better, by using a pair stack, second element is for storing the min

class MinStack {
public:
    stack<pair<int,int>> stk;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(stk.empty()){
            stk.push(make_pair(x,x));
        }
        else{
            int m=stk.top().second;
            if(x < m){
                m=x;
            }
            stk.push(make_pair(x,m));
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;

    }
    
    int getMin() {  
        return stk.top().second;
    }
};

// this one is interesting, similar to my soln but uses a stack from scratch

class Node{
    public:
    Node *next;
    int val;
    Node(int _n)
    {
        next = NULL;
        val = _n;
    }
};

class MinStack {
public:
    /** initialize your data structure here. */

    Node* head;
    map<int,int> m;
    
    MinStack() {
        head = NULL;
    }
    
    void push(int x) {
        if(!head)
        {
            head = new Node(x);
            m.insert({x,1});
        }
        else
        {
            Node* tmp = new Node(x);
            tmp->next = head;
            head = tmp;
            if(m.find(x) == m.end())
                m.insert({x,1});
            else
                m[x]++;

        }
    }
    
    void pop() {
        if(!head) return;
        else{
            m[head->val]--;
            if(m[head->val]==0) m.erase(head->val);
            head = head->next;
            
        }
            
    }
    
    int top() {
        if(!head) return -1;
        else return head->val;
    }
    
    int getMin() {
        if(!m.empty())
        {
             return (m.begin())->first;
        }
        else return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
