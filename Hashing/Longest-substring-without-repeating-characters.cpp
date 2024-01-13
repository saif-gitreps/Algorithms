class Solution {
//attempt 1 worked till 407/900 test cases.
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = -1;
        int prev_len = 0;
        set<char> mySet;
        for(int i = 0 ; i<s.size(); i++){
            mySet.insert(s[i]);
            if(mySet.size()>prev_len){
                prev_len = mySet.size();
                max_len = max(max_len,prev_len);
            }
            else{
                prev_len = 1;
                set<char> newSet;
                newSet.insert(s[i]);
                mySet = newSet;
            }
        }
        return max_len==-1?0:max_len;
    }
};
class Solution {
//attempt 2: cant figure out the damn thing 
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = -1;
        int seq = 0;
        unordered_map<char,int> mp;
        for(int i = 0 ; i<s.size(); i++){
            if(mp.count(s[i])==false){
                mp[s[i]] = i;
                seq++;
                max_len = max(max_len,seq);
            }
            else{
                seq = abs((mp[s[i]]+1)-(i+1));
                mp[s[i]] = i;
                 max_len = max(max_len,seq);
            }
        }
        return max_len==-1?0:max_len;
    }
};

class Solution {
// HAHHAHAHA, solved it , bascially when we find a unique guy , we store his index. then when we encounter something non-unique, we jump back to that index.
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0;
        int seq = 0;
        unordered_map<char,int> mp;
        for(int i = 0 ; i < s.size(); i++){
            // we also store the index of the unique one
            if(!mp.count(s[i])){
                seq++;
                mp[s[i]] = i;
                mx = max(mx, seq);
            }
            else{
                seq = 0;
                i = mp[s[i]];
                mp = {};
            }
        }
        return mx;
    }
};


class Solution {
// this is also called sliding window technique.
// interesting solution , we keep two pointers , 'j' pointer will keep on moving if we keep on getting unique chars.
// if we get a duplicate char, then we erase using the 'i' pointer , incre 'i'.
// meanwhile we keep a max of (j - i), try simulating it yourself. its easy.
public:
	int lengthOfLongestSubstring(string s) 
	{
		unordered_set<char> set;
    
		int i = 0, j = 0, n = s.size(), ans = 0;
    
		while( i<n && j<n)
		{
			if(set.find(s[j]) == set.end()) //If the character does not in the set
			{
				set.insert(s[j++]); //Insert the character in set and update the j counter
				ans = max(ans, j-i); //Check if the new distance is longer than the current answer
			}
			else
			{
				set.erase(s[i++]); 
				/*If character does exist in the set, ie. it is a repeated character, 
				we update the left side counter i, and continue with the checking for substring. */
			}
		}
    
		return ans;
	}
};
