// I mean this works well on theory

bool are_words_pre(string a, string b){
    unordered_set<char> s;

    for(auto c : a){
        s.insert(c);
    }
    for(auto c : b){
        s.insert(c);
    }

    if(a.size() > b.size()){
        return s.size() == a.size() && abs(a.size() - b.size()) == 1;
    }
    else if(a.size() < b.size()){
        return s.size() == b.size() && abs(a.size() - b.size()) == 1;
    }
    return false;
}

bool compare_words(string a, string b){
    return a.size() < b.size();
}

int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), compare_words);

    for(auto word : words){
        debug(word);
    }
    
    int ans = 0;

    for(int i = 0; i < words.size(); i++){
        string curr = words[i];
        int count = 1;
        for(int j = i + 1; j < words.size(); j++){
            if(i != j && are_words_pre(curr, words[j])){
                curr = words[j];
                count++;
            }
        }
        ans = max(count, ans);
    }

    return ans;
}
