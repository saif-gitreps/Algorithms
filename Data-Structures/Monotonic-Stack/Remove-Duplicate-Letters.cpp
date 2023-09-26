Concept of monotinic stack. 
It is basically a stack that stores element in either increaseing order or decreasing order.
So the solution goes like this ->
- we first hash all the elements.
- we keep a stack that keep stuffs in incrasing order. 
- if we find an element that is disrupting the increasing order of the stack, 
- we remove everything from the stack (till we find the element in the stackk that is smaller than the potential inserting element.
- but we make sure the frequency of the removing element in the stackk is not 0 , if it is 0 , we leave it as it is.
- At the same time if we have a visited hash map , if we already set it up inside the stack we hash it true.


class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> mp(26,0);
        stack<char> stacc;
        vector<int> visit(26,false);
        for(int i = 0 ; i < s.size() ; i ++){
            mp[s[i] - 'a'] ++;
        }
        for(int i = 0 ; i < s.size() ; i ++){
            if( visit[s[i] - 'a'] == true){
                mp[ s[i] - 'a']--;
                continue;
            }
            while(stacc.empty() == false &&
                  stacc.top() > s[i] &&
                  //frequency of the one that is in the stacc must not b 0.
                  mp[stacc.top() - 'a' ] > 0
                ){
                    visit[ stacc.top() - 'a'] = false;
                    stacc.pop();
            }
            stacc.push(s[i]);
            visit[s[i] - 'a'] = true;
            mp[s[i] - 'a']--;
        }
        string new_str = "";
        while( stacc.empty() != true){
            new_str += stacc.top(); stacc.pop();
        }
        reverse(new_str.begin(),new_str.end());
        return new_str;
    }
};
