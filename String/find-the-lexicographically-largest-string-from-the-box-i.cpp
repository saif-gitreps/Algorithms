    public String answerString(String word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        int n = word.length(), m = n - numFriends + 1;
        String res = "", cur = "";
        for (int i = 0; i < n; ++i) {
            cur = word.substring(i, Math.min(i + m, n));
            if (res.compareTo(cur) < 0) {
                res = cur;
            }
        }
        return res;
    }


class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        string res = "";
        for (int i = 0 ; i < word.size() ; i++) 
            res = max(res, word.substr(i, word.length() - numFriends + 1));
        return res;
    }
};


// absolute bruteforce, try to trace using "dbca" and num = 3

#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"

string maxStr = "";

void dfs(string& word, int index, int remainingCuts, vector<string>& current) {
    int n = word.size();
    if (remainingCuts == 0) {
        if (index < n) {
            current.push_back(word.substr(index));
            for (string& s : current) {
                debug(s);
                if (s > maxStr) maxStr = s;
            }

            debug("--");
            current.pop_back();
        }
        return;
    }

    for (int i = index; i < n - remainingCuts; ++i) {
        string part = word.substr(index, i - index + 1);
        current.push_back(part);
        debug(part);
        dfs(word, i + 1, remainingCuts - 1, current);
        current.pop_back();
    }
}

string answerString(string word, int numFriends) {
    vector<string> current;
    dfs(word, 0, numFriends - 1, current);
    return maxStr;
}
    
int main() {
    string words = "dbca";
    int numFriends = 3;

    cout << answerString(words, numFriends);
}


