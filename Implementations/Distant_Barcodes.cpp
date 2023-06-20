class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
      // worked till 18 cases.
        map<int,int> mp;
        for(int i=0;i<b.size();i++){
            mp[b[i]]++;
        }
        vector<int> ans;
        ans.push_back(b[0]);
        int curr = b[0];
        mp[curr]--;
        for(int i=1;i<b.size();i++){
            for(auto x: mp){
                    if(x.second>0 && curr!=x.first){
                        curr = x.first;
                        mp[curr]--;
                        break;
                    }
                    else{
                        continue;
                    }
               }
            if(ans.back()!=curr)
                    ans.push_back(curr);
        }
        return ans;
    }

};
