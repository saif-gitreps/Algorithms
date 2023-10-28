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

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */


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

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
