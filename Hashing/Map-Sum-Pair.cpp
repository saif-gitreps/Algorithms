class MapSum {
// naive solution O(N^2).
public:
    map<string, int> mp;
    MapSum() {
    }
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int len = prefix.size();
        int sum = 0;
        for(auto s : mp){
            if(s.first.substr(0, len) == prefix)
                sum += s.second;
        }
        return sum;
    }
};


/*
In a std::map with keys "apple" and "app", and assuming you're calling mp.lower_bound("ap"), 
here's how the iterator would iterate:

The lower_bound() function will return an iterator pointing to the first element whose key is not less than "ap". 
In this case, it would point to "app",
because it is the first key in lexicographical order that is not less than "ap".

If you were to iterate further using the returned iterator, it would still point to "app" 
because there are no keys after it that are not less than "ap" in lexicographical order.

So, essentially, the iterator would point to the element with key "app". 
If you attempt to increment the iterator further, it would still point to the same element 
because it's the first element in the map that's not less than "ap".
*/

class MapSum {
public:
    /** Initialize your data structure here. */    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int sum = 0, n = prefix.size();
        for (auto it = mp.lower_bound(prefix); it != mp.end() && it->first.substr(0, n) == prefix; it++) 
            sum += it->second;
        return sum;
    }
private:
    map<string, int> mp;
};



