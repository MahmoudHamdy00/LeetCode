class RandomizedSet {
    //unordered_set<int> _elems;
    vector<int> _nums;
    unordered_map<int, int> _positions;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(_positions.find(val) != _positions.end())
            return false;
        _nums.push_back(val);
        _positions.insert({val, _nums.size()-1});
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(_positions.find(val) == _positions.end())
            return false;
        int pos = _positions[val];
        _nums[pos] = _nums[_nums.size()-1];
        _positions[_nums[pos]] = pos;
        _nums.pop_back();
        _positions.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return _nums[rand() % _nums.size()];
    }
};