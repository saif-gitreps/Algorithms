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
