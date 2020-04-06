static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();



static constexpr const size_t CHARSET_SIZE = 26;

struct mhash 
{
	inline size_t operator()(const char* s) const {
		return hash_code(s, strlen(s));
	}
	
	static size_t hash_code(const char* s, size_t n)
	{
		uint16_t count[26] = { 0 };
        for (size_t i = 0; i < n; i++) 
            ++count[s[i] - 'a'];
        
        size_t h = 0;
        for (auto x : count) 
            h = h * 31 + x;
        return h;
	}
};


inline bool is_anagram(const char* s1, size_t n1,
                       const char* s2, size_t n2)
{
	if (n1 != n2) return false;
	
	unsigned int b = 0; // sum of all characters
    unsigned int a = 0; // bitset of charset

	// first pass
    for (size_t i = 0; i < n1; i++) {
        char c = s1[i];
        a |= 1 << (c - 'a'); // set bit
        b += c; // add  (WARNING: potentially may overflow!)
    }

	// second pass
    for (size_t i = 0; i < n1; i++) {
        char c = s2[i];
        a &= ~(1 << (c - 'a')); // unset bit
        b -= c; // subtract
    }
        
	// verify
    return ((a ^ b) == 0); // faster than 'a == 0 && b == 0'
}




struct anagram_equal
{
	inline bool operator()(const char* lhs,
	                       const char* rhs) const {
		return is_anagram(lhs, strlen(lhs), rhs, strlen(rhs));
	}
};



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& inputs) 
    {
        vector<vector<string>> results;
        
        unordered_map< const char*, size_t, mhash, anagram_equal > mset;
        mset.reserve(inputs.size());
        for(const auto& s : inputs)
        {
            auto it = mset.find(s.data());
            if (it == mset.end()) {
                results.emplace_back(1, s);
                mset.emplace(s.data(), results.size()-1);
            } else {
                results[it->second].emplace_back(s);
            }
        }
        return results;
    }
};