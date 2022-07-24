class FoodRatings {
    map<string,multiset<int>>cuisines_ratings;
    map<string,int>food_to_rate;
    map<string,string>food_to_cuisines;
    map<pair<string,int>,set<string>>rate_to_food;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();++i){
            cuisines_ratings[cuisines[i]].insert(ratings[i]);
            food_to_rate[foods[i]]=ratings[i];
            food_to_cuisines[foods[i]]=cuisines[i];
            rate_to_food[{cuisines[i],ratings[i]}].insert(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        int old_rate=food_to_rate[food];
        string c=food_to_cuisines[food];
        rate_to_food[{c,old_rate}].erase(food);
        
        food_to_rate[food]=newRating;
        
        rate_to_food[{c,newRating}].insert(food);
        
        cuisines_ratings[c].erase(cuisines_ratings[c].find(old_rate));
        cuisines_ratings[c].insert(newRating);
    }
    
    string highestRated(string cuisine) {
        /*for(auto it:cuisines_ratings){
            cout<<it.first<<":\n";
            for(auto i:it.second){
                cout<<i<<":";
                for(auto s:rate_to_food[i]){
                    cout<<s<<" ";
                }
                cout<<endl;
            }
        }*/
        int high_rate=*cuisines_ratings[cuisine].rbegin();
        return *rate_to_food[{cuisine,high_rate}].begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */