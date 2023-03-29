class Solution {
public:
  // my sol. works.
    bool canConstruct(string ransomNote, string magazine) {
        sort(magazine.begin(),magazine.end());
        sort(ransomNote.begin(),ransomNote.end());
        int found = 0,n = magazine.size();
        int k =0;
        for(int i=0;i<n;i++){
            if(ransomNote[k]==magazine[i]){
                k++;
            }
        }
        return (k==ransomNote.size())? true:false;
    }
};

class Solution {
public:
  // soln in o(n). using hashing.
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26] = {0};
        for(int i=0;i<magazine.size();i++){
            freq[magazine[i]-'a']++;
        }
        for(int i=0;i<ransomNote.size();i++){
            if(freq[ransomNote[i]-'a']==0){
                return false;
            }
            freq[ransomNote[i]-'a']--;
        }
        return true;
    }
}
