class FirstUnique
{
public:
	unordered_map<int,int> st;
	list<int> lst;

	FirstUnique(vector<int> &nums)
	{
		for (int i : nums)
		{
            if(++st[i]==1)
			    lst.push_back(i);
		}
	}

	int showFirstUnique()
	{
		if (lst.empty())
			return -1;
		while (!lst.empty() && st[lst.front()] > 1)
			lst.pop_front();
		if (lst.empty())
			return -1;
		return lst.front();
	}

	void add(int value)
	{
        if(++st[value]==1)
		    lst.push_back(value);
		
	}
};
/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */