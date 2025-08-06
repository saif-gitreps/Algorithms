class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        for (int i = 0; i < fruits.size(); i++) {
            mp[fruits[i]]++;
        }

        int mx = 0;
        int mx_fruit;
        int second_mx = 0;
        int second_mx_fruit;

        for (auto it: mp) {
            if (it.second > mx) {
                mx = it.second;
                mx_fruit = it.first;
            }

            if (it.second > second_mx && it.second < mx && it.first != mx_fruit){
                second_mx = it.second;
                second_mx_fruit = it.first;
            }
        }

        return mx + second_mx;
    }
};

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        for (int i = 0; i < fruits.size(); i++) {
            mp[fruits[i]]++;
        }

        int mx = 0;
        int mx_fruit;
        int second_mx = 0;
        int second_mx_fruit;

        for (auto it: mp) {
            if (it.second > mx) {
                mx = it.second;
                mx_fruit = it.first;
            }
        }

        for (auto it: mp) {
            if (it.second > second_mx && it.second <= mx && it.first != mx_fruit){
                second_mx = it.second;
            }
        }

        return mx + second_mx;
    }
};


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if (fruits.size() == 1) {
            return 1;
        }
        int fast =  1;
        int slow = 0, ans = 0;
        unordered_map<int, int> mp;
        mp[fruits[slow]]++;
        for (; fast < fruits.size() && slow < fruits.size(); fast++) {
            mp[fruits[fast]]++;

            if (mp.size() > 2) {
                int key_to_delete = fruits[slow];
                while (key_to_delete == fruits[slow]) {    
                    mp[fruits[slow++]]--;
                    
                    if (mp[key_to_delete] == 0) {
                        mp.erase(key_to_delete);
                        break;
                    }
                }
            }
            ans = max(ans, fast - slow + 1);
        }   

        return ans;
    } 

};
