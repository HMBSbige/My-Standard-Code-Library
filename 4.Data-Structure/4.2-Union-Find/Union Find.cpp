/*
���鼯
�ṹ�壺DisjoinSet
��Ա������
    vector<int> father //Ԫ�صĸ��׽ڵ㣬����Ԫ�صĸ���Ϊ����
    vector<int> rank   //����Ԫ���������ϵ�rank
��Ա������
    DisjoinSet(int n);       //��ʼ����n��Ԫ�أ����ڵ�������
    ���Ӷȣ�O(n)
    int find(int v);         //����v���ڼ��ϵĴ���Ԫ
    ���Ӷȣ���̯O(1)
    void merge(int x,int y); //�ϲ�x���ڵļ�����y���ڼ���
    ���Ӷȣ���̯O(1)
*/
struct DisjoinSet{
    std::vector<int> father,rank;

    DisjoinSet(int n):father(n),rank(n){
        for(int i=0;i<n;++i)
            father[i]=i;
    }
    int find(int v){
        return father[v]=father[v]==v?v:find(father[v]);
    }

    void merge(int x,int y){
        int a=find(x),b=find(y);
        if(rank[a]<rank[b])
            father[a]=b;
        else{
            father[b]=a;
            if(rank[b]==rank[a])
                ++rank[a];
        }
    }
};