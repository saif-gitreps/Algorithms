question in a real interview before?  
Subscribe to see which companies asked this question.

Related Topics 

C++	
1
class Solution {
2
public:
3
    int findContentChildren(vector<int>& g, vector<int>& s) {
4
        int mx = 0;
5
        for(auto n : s){
6
            mx = max(mx, n);
7
        }
8
​
9
        int count = 0;
10
        for(auto n: g){
11
            if(n >= mx){
12
                count++;
13
            }
14
        }
15
        
16
        return count;
17
    }
18
};
