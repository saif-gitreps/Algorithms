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
