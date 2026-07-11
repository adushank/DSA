class Solution {
public:
class DSU{
    vector<int>parent,size;
    public:
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }}

        int find(int x){
            if(parent[x]==x)return x;
            return parent[x]=find(parent[x]);
            

        }
        void unite (int u,int v){
            u =find(u);
            v=find(v);
            if(u==v)return;
            if(size[u]<size[v])
                swap(u,v);
                parent[v]=u;
                size[u]+=size[v];
            
        }
    };

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(int i = 0; i < edges.size(); i++) {
    dsu.unite(edges[i][0], edges[i][1]);
}
          unordered_map<int, int> vertexCnt;
        unordered_map<int, int> edgeCnt;

        // Count vertices
        for (int i = 0; i < n; i++) {
            vertexCnt[dsu.find(i)]++;    // root--->  vertex
        }

        // Count edges
        for (auto &e : edges) {
            edgeCnt[dsu.find(e[0])]++;     // root---->edges
        }

        int ans = 0;
        for(auto [root,v] :  vertexCnt){
            int edges_required = v *(v-1)/2;   // 
            if(edges_required==edgeCnt[root]){
                ans ++;
            }
        }

        return ans;;


        
    }
};