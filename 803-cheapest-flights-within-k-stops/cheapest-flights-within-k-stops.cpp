class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
       for(auto e : flights){
            int u =e[0];
            int v =e[1];
            int w =e[2];

            adj[u].push_back({v,w});
        }
          vector<vector<int>> dist(n,
                    vector<int>(k+2,1e7));
       priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
       dist[src][0]=0;
      pq.push({0, src, 0});
       while(!pq.empty()){
        auto [d, u, used] = pq.top();
        pq.pop();


        if(u ==dst )return d;
        if(used >k)continue;
        if(d>dist[u][used])continue;
        for(auto [v,w] : adj[u]){
        if(dist[v][used +1]> dist[u][used] +w){
            dist[v][used +1] = dist[u][used] +w;
           pq.push({dist[v][used+1], v, used+1});
        }
       }}
       int ans =1e7;
       for(int i =0;i<=k;i++){
         ans =min(ans ,dist[dst][i]);
       }
      return ans==1e7 ? -1 : ans;

        
    }
};