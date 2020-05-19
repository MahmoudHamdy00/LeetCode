class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>> v) {
        for (auto& it : v)sort(it.begin(), it.end());

        vector<int> ans;
        for (int i = 0; i < v.size(); i++) {
            bool exist = 0;
            for (int j = 0; j < v.size() && !exist; j++)
                if (j != i && v[j].size() > v[i].size()) {
                int cur = 0, idx = -1;
                while (cur < v[i].size()) {
                    idx = lower_bound(v[j].begin() + idx + 1, v[j].end(), v[i][cur]) - v[j].begin();
                    if (idx != v[j].size() && v[i][cur] == v[j][idx])
                        cur++;
                    else
                        break;
                }
                if (cur == v[i].size()) {
                    exist = 1;
                    break;
                }
            }
            if (!exist)
                ans.push_back(i);
        }
        return ans;
    }
};