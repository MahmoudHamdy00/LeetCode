class Solution {
public:
	vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
		set < pair<int, pair< int, int>>>st, st2;
		int idx = 0;
		for (int i : servers)st.insert({ 0,{i,idx++} });
		vector<int>ret(tasks.size());
		int i = 0;
		int t = 0;
		while (i < tasks.size()) {
			if (st.empty()) {
				pair<int, pair< int, int>> add = *st2.begin();
				t = max(t, add.first);
				add.first = 0;
				st.insert(add);
				st2.erase(st2.begin());
			}
			auto cur = *st.begin();
			st.erase(cur);
			cur.first = t + tasks[i];
			st2.insert(cur);
			ret[i] = cur.second.second;
			i++;

			t = max(t, i);
			while (!st2.empty() && st2.begin()->first <= t) {
				pair<int, pair< int, int>> add = *st2.begin();
				add.first = 0;
				st.insert(add);
				st2.erase(st2.begin());
			}
		}
		return ret;
	}
};