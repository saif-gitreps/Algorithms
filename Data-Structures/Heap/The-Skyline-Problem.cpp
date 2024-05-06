bool comparator(pair<int,int> a, pair<int,int> b){
    if(a.first != b.first){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }   
}
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // make a pair array of s.point(h is -ve) and e.point(h is +ve).
        vector<pair<int,int>> p;

        for(auto b : buildings){
            p.push_back( {b[0],-b[2]} );
            p.push_back( {b[1],b[2]} );
        }

        // sort it in ASC.
        sort(p.begin(), p.end(), comparator);
        
      // using multiset instead of pq because we need to find and delete in between.
        multiset<int> pq;
        vector<vector<int>> ans;

        pq.insert(0);
        int current_height = 0;

        for(auto s : p){
            
            auto it = pq.rbegin();

            if(s.second < 0){
                pq.insert(abs(s.second));
            }
            else{
                pq.erase(pq.find(s.second));
            }

            if(it != pq.rend() && current_height != *it){
                ans.push_back(
                    {s.first, *it}
                );
                current_height = *it;
            }
        }
        return ans;
    }
};
