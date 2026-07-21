class Solution {
public:


int res =-1e7;
vector<vector<int>>adj;
vector<int>dp;

int dfs(int u,int p,string &s){
        int best1 = 0;
       int best2 = 0;

for(auto child: adj[u]){
    
     if(child==p)   continue;   
    

    dfs(child,u,s);
    if(s[child]==s[u])continue ;
    
 if (dp[child] > best1) {
    best2 = best1;
    best1 = dp[child];
}
else if (dp[child] > best2) {
    best2 = dp[child];
}

 
 

}


 dp[u]=best1 +1;   // jo upar bhejna h 
int ans=max(dp[u],best1 +best2+1);
res=max(res,ans);                                // temp ----->dp[u]
return dp[u];
}




    int longestPath(vector<int>& parent, string s) {
     

 int n =parent.size();
        adj.resize(n);
        dp.resize(n,1);
        for(int i =1;i<n;i++){
        int u =parent[i];
        int v =i;
        

        adj[u].push_back(v);
        adj[v].push_back(u);
        
        

        }
     dfs(0,-1,s);
   return res;
       
    }
};











