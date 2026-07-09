class DisjointSet{
       vector<int>rank,parent,size;
 
 public: 
     DisjointSet(int n) // constructer
     {
         rank.resize(n+1,0);
         parent.resize(n+1);
         size.resize(n+1);

         for(int i=0;i<n;i++){
             parent[i]=i;
             size[i]=1;
         }
     }    
     
     int findUpar(int node){
          if(node==parent[node])return node;

          return parent[node]=findUpar(parent[node]);
     }

     void unionByrank(int u,int v){
           int ulp_u=findUpar(u);
           int ulp_v=findUpar(v);

           if(ulp_u==ulp_v){
                return ;
           }

           if(rank[ulp_u]<rank[ulp_v]){
                  parent[ulp_u]=ulp_v;
           }
           else if(rank[ulp_v]<rank[ulp_u]){
                  parent[ulp_v]=ulp_u;
           }
           else{
               parent[ulp_v]=ulp_u;
               rank[ulp_u]++;
           }

     }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
            
                 DisjointSet ds(n);

                 for(int i=0;i<n-1;i++){
                      if(nums[i+1]-nums[i]<=maxDiff){
                               ds.unionByrank(i,i+1);
                      }
                 }

                  vector<bool>ans;
                 for(auto it:queries){
                       int u=it[0];
                       int v=it[1];

                       if(ds.findUpar(u)==ds.findUpar(v)){
                                 ans.push_back(true);
                       }
                       else{
                           ans.push_back(false);
                       }
                 }

                 return ans;


                      

    }
};