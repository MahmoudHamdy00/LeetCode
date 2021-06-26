class Solution {
public:
	string removeOccurrences(string s, string part) {
		int idx = s.find(part);
		while (~idx) {
			s.replace(idx, part.size(), "");
			idx = s.find(part);
		}
		return s;
	}
};