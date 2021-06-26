class MovieRentingSystem {
private:
    map<int,set<pair<int,int>>>movies;
    map<pair<int,int>,int>moviePrice;
    set<vector<int>>rented;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
       for(int i=0;i<entries.size();++i){
           movies[entries[i][1]].insert({entries[i][2],entries[i][0]});
           moviePrice[{entries[i][0],entries[i][1]}]=entries[i][2];
       }
        
    }
    
    vector<int> search(int movie) {
        vector<int>ret;
        int cnt=0;
        for(auto it:movies[movie]){
            ret.push_back(it.second);
            ++cnt;
            if(cnt==5)break;
        }
        return ret;
    }
    
    void rent(int shop, int movie) {
        int price=moviePrice[{shop,movie}];
        rented.insert({price,shop,movie});
        movies[movie].erase({price,shop});
    }
    
    void drop(int shop, int movie) {
        int price=moviePrice[{shop,movie}];
        rented.erase({price,shop,movie});
        movies[movie].insert({price,shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>>ret;
        int cnt=0;
        for(auto it:rented){
            ret.push_back({it[1],it[2]});
            ++cnt;
            if(cnt==5)break;
        }
        return ret;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */