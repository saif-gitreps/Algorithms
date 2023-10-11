class LRUCache {
// My naive attempt lol
private:
vector<pair<int,int>> mp;
int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        for(int i = 0 ;i < this->mp.size(); i++){
            if(this->mp[i].first == key){
                return this->mp[i].second;
            }
        }
        return -1;
    }
    void put(int key, int value) {
        if(this->mp.size() == this->capacity){
            this->mp.pop_back();
        }
        this->mp.push_back({key,value});
    }
};

class LRUCache {
//proper solution.
private:
public:
    class node{
        public:
        int val;
        int key;
        node *next;
        node *prev;
        node(int key,int val){
            this->key = key;
            this->val = val;
        }
    };
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;
    unordered_map<int,node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node *newNode){
        node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(node *delNode){
        node *delprev = delNode->prev;
        node *delnext = delNode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()){
            node *resultNode = mp[key];
            int result = resultNode->val;
            mp.erase(key);
            deleteNode(resultNode);
            addNode(resultNode);
            mp[key] = head->next;
            return result;
        }
        return -1;
    }
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            node *existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode); 
        }
        if(mp.size() == cap){
            // we remove the last element.
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key, value));
        mp[key] = head-> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
