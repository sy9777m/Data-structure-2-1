
// 정점 집합들을 관리하는 클래스.
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
        // 루트 (set의 대표노드)를 표시하기 위해 부모를 -1로 둡니다.
        // 가장 초기에는 연결이 되어있는 노드들이 없으므로, 모든 노드가 다 루트입니다
        bool IsRoot(int i) { return parent[i] < 0; }
        // 부모가 -1 (음수)이면 루트 노드입니다
        
        int findSet(int vertex){
            int id = vertex;
            while(!IsRoot(id)){
                id = parent[id];
            }
            return id;
        }
        // 주어진 노드의 루트 (set의 대표노드)를 찾습니다

        void unionSets(int s1, int s2) {
            parent[s1] = s2;
            size--;
        }
        //주어진 두 set s1과 s2을 합칩니다 (루트 노드로 주어짐). 
        //s1의 root node를 s2로 정의합니다.
};
