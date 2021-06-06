
// ���� ���յ��� �����ϴ� Ŭ����.
class VertexSets {
    protected:
        int parent[MAX_VTXS];
        int size;				
    public:
        VertexSets(int nSets){ 
            size = nSets;
            for(int i = 0; i < nSets; i++){
                parent[i] = -1;
            }
        } 
        // ��Ʈ (set�� ��ǥ���)�� ǥ���ϱ� ���� �θ� -1�� �Ӵϴ�.
        // ���� �ʱ⿡�� ������ �Ǿ��ִ� ������ �����Ƿ�, ��� ��尡 �� ��Ʈ�Դϴ�
        bool IsRoot(int i) { return parent[i] < 0; }
        // �θ� -1 (����)�̸� ��Ʈ ����Դϴ�
        
        int findSet(int vertex){
            int id = vertex;
            while(!IsRoot(id)){
                id = parent[id];
            }
            return id;
        }
        // �־��� ����� ��Ʈ (set�� ��ǥ���)�� ã���ϴ�

        void unionSets(int s1, int s2) {
            parent[s1] = s2;
            size--;
        }
        //�־��� �� set s1�� s2�� ��Ĩ�ϴ� (��Ʈ ���� �־���). 
        //s1�� root node�� s2�� �����մϴ�.
};
