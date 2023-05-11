class Solution {
public:
  // first attempt, works from 1-3 , yay.

    string ans(string num,int i,int n){
        if(i==n){
            return num;
        }
        else{
            unordered_map<int,int> mp;
            for(int i=0;i<num.size();i++){
                int number = num[i]-48;
                mp[number]++;
            }
            string sender = "";
            for(auto x: mp){
                sender += x.second+48;
                sender += x.first+48;
            }
            
            return ans(sender,i+1,n);
        }
    }

    string countAndSay(int n) {
         return ans("1",1,n);
    }
};
