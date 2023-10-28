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
