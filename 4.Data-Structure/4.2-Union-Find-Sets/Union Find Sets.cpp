struct DisjoinSet {
	std::vector<int> father, rank,max;
	int _max = 1;

	DisjoinSet(int n) :father(n), rank(n),max(n,1){
		for (int i = 0; i<n; ++i)
			father[i] = i;
	}
	int find(int v) {
		return father[v] = father[v] == v ? v : find(father[v]);
	}
	void merge(int x, int y) {
		int a = find(x), b = find(y);
		if (rank[a]<rank[b]){
			father[a] = b;	
			if (_max < (max[b] += max[a]))
				_max = max[b];
		}
		else {
				father[b] = a;
				if (_max < (max[a] += max[b]))
					_max = max[a];
				if (rank[b] == rank[a])
					++rank[a];					
			 }
	}
};
