class LRUCache {
public:
	LRUCache(int capacity) {
		_capacity = capacity;
	}

	int get(int key) {
		auto it = _cache.find(key);
		if (it == _cache.end())return -1;
		update(it);
		return it->second.first;
	}

	void put(int key, int value) {
		auto it = _cache.find(key);
		if (it != _cache.end()) {
			update(it);
			_cache[key] = { value,_msu.begin() };
			return;
		}
		if (_cache.size() == _capacity) {
			_cache.erase(_msu.back());
			_msu.pop_back();
		}
		_msu.push_front(key);
		_cache.insert({ key,{value,_msu.begin()} });
		return;
	}
private:
	int _capacity;
	unordered_map<int, pair<int, list<int>::iterator>>_cache;
	list<int>_msu;
	void update(unordered_map<int, pair<int, list<int>::iterator>>::iterator& it) {
		_msu.erase(it->second.second);
		_msu.push_front(it->first);
		it->second.second = _msu.begin();
	}
};