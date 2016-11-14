/*
���鼯
�ṹ�壺DisjoinSet
��Ա������
    vector<int> father //Ԫ�صĸ��׽ڵ㣬����Ԫ�صĸ���Ϊ����
    vector<int> rank   //����Ԫ���������ϵ�rank
    _max               //��󼯺ϵ�Ԫ�ظ���
��Ա������
    DisjoinSet(int n);       //��ʼ����n��Ԫ�أ����ڵ�������
    ���Ӷȣ�O(n)
    int find(int v);         //����v���ڼ��ϵĴ���Ԫ
    ���Ӷȣ���̯O(1)
    void merge(int x,int y); //�ϲ�x���ڵļ�����y���ڼ���
    ���Ӷȣ���̯O(1)
*/
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