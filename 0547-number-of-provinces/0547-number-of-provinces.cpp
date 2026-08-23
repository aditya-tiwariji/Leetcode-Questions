class Solution {
public:
    class DisjointSet {
        public:

        vector<int> parent, size;

        DisjointSet(int n) {
            parent.resize(n);
            size.resize(n, 1);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
    

    int findUpar(int u){
           
           if(parent[u]==u)return u;

           return parent[u]=findUpar(parent[u]);
    } 

    void UnionBysize(int u,int v){
          
            int par_u=findUpar(u);
            int par_v=findUpar(v);

            if(par_u==par_v)return;

            if(size[par_u]<size[par_v]){
                   parent[par_u]=par_v;
                   size[par_v]+=size[par_u];
            }
            else{
                 parent[par_v]=par_u;
                 size[par_u]+=size[par_v];
            }
    }
    }; 

    int findCircleNum(vector<vector<int>>& isConnected) {

            int n = isConnected.size();
             
             DisjointSet ds(n);
             
             int p=n;
            for(int i=0;i<n;i++){
                  for(int j=0;j<n;j++){
                       
                       if(isConnected[i][j]){
                             
                             if(ds.findUpar(i)!=ds.findUpar(j)){
                                ds.UnionBysize(i,j);
                                p--;
                             }
                       }
                  }
            }

            return p;
    }
};