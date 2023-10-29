class FoodRatings {
// attempt 1 after so many hours 24/77 cases passed.
public:
    map<string,int> cuisMaxMap;
    map<string,string> foodCuisMap;
    map<string,int> food;
    FoodRatings(vector<string>& foods, vector<string>& c, vector<int>& rate) {
        for(int i = 0; i < c.size(); i++){
            cuisMaxMap[c[i]] = max(cuisMaxMap[c[i]] , rate[i]);
            foodCuisMap[foods[i]] = c[i];
            food[foods[i]] = rate[i]; 
        }
    }
    void changeRating(string checkFood, int newRating) {
        food[checkFood] = newRating;
        cuisMaxMap[foodCuisMap[checkFood]] = 
        max(cuisMaxMap[foodCuisMap[checkFood]] , newRating);   
    }
    string highestRated(string cuisine) {
        for(auto s : food){
            if(s.second == cuisMaxMap[cuisine]){
                return s.first;
            }
        }
        return "";
    }
};


class FoodRatings {
//2nd attempt same result
public:
    map<string,int> cuisMaxMap;
    map<string,string> foodCuisMap;
    map<string,int> food;
    FoodRatings(vector<string>& foods, vector<string>& c, vector<int>& rate) {
        for(int i = 0; i < c.size(); i++){
            cuisMaxMap[c[i]] = max(cuisMaxMap[c[i]] , rate[i]);
            foodCuisMap[foods[i]] = c[i];
            food[foods[i]] = rate[i]; 
        }
    }
    void changeRating(string checkFood, int newRating) {
        food[checkFood] = newRating;
        if(cuisMaxMap[foodCuisMap[checkFood]] == food[checkFood]){
            cuisMaxMap[foodCuisMap[checkFood]] = 0;
            for(auto s : food){
               cuisMaxMap[foodCuisMap[checkFood]] = 
               max(cuisMaxMap[foodCuisMap[checkFood]] , s.second);   
            }
        }
        else{
           cuisMaxMap[foodCuisMap[checkFood]] = 
           max(cuisMaxMap[foodCuisMap[checkFood]] , newRating);
        } 
    }
    string highestRated(string cuisine) {
        for(auto s : food){
            if(s.second == cuisMaxMap[cuisine]){
                return s.first;
            }
        }
        return "";
    }
};


class FoodRatings {
// this solution worked, learned so many things abouts c++ libarries.
public:
    unordered_map<string, set<pair<int,string>>> cuis_rating;
    unordered_map<string,string> food_cuis;
    unordered_map<string,int> food_rating;
    FoodRatings(vector<string>& foods, vector<string>& c, vector<int>& rate) {
        for(int i = 0; i < c.size(); i++){
            // here -rate means higher rating will come first
            // And we really dont have to worry about strings,
            // strins will be stored lexographically by default.
            cuis_rating[c[i]].insert( { -rate[i], foods[i] } );
            food_cuis[foods[i]] = c[i];
            food_rating[foods[i]] = rate[i];
        }
    }
    void changeRating(string food, int newRating) {
        auto &cuisine = food_cuis.find(food)->second;
        cuis_rating[cuisine].erase({-food_rating[food], food});
        cuis_rating[cuisine].insert({-newRating, food});
        food_rating[food] = newRating;
    }
    string highestRated(string cuisine) {
        return begin(cuis_rating[cuisine])->second;
    }
};


// here there is a logical use of a comparator, if a==b then we sort using the second value.
struct comp {
    bool operator()(pair<int, string>& a, pair<int, string>& b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};

class FoodRatings {
public:

    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, comp>> cuisinemap;
    unordered_map<string, string> menu;
    unordered_map<string, int> ratemap;

    FoodRatings(vector<string>& foods, vector<string>& c, vector<int>& r) {
        for (int i = 0; i < foods.size(); i++) {
            cuisinemap[c[i]].push({r[i], foods[i]});
            menu[foods[i]] = c[i];
            ratemap[foods[i]] = r[i];
        }
    }

    void changeRating(string food, int newRating) {
        ratemap[food] = newRating;
        cuisinemap[menu[food]].push({newRating, food});
    }

    string highestRated(string cuisine) {
        auto top_food = cuisinemap[cuisine].top();

        while (ratemap[top_food.second] != top_food.first) {
            cuisinemap[cuisine].pop();
            top_food = cuisinemap[cuisine].top();
        }

        return top_food.second;
    }
};
