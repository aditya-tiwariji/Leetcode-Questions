class Solution {
public:
class DisjointSet{
           vector<int>parent,size;

           public:

           DisjointSet(int n){
                 
                     parent.resize(n);
                     size.resize(n,1);

                     for(int i=0;i<n;i++){
                           parent[i]=i;
                     }
           }

        int findUpar(int node){

              if(parent[node]==node)return node;
              return parent[node]=findUpar(parent[node]);
        }   

        void unionBysize(int u,int v){
               
                int up_u=findUpar(u);
                int up_v=findUpar(v);

                if(up_u==up_v)return;

                if(size[up_v]<=size[up_u]){
                        size[up_u]+=size[up_v];
                        parent[up_v]=parent[up_u];
                }
                else{
                      size[up_v]+=size[up_u];
                      parent[up_u]=parent[up_v];
                }
        }
};
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
                int n=nums.size();

                DisjointSet ds(n);

                vector<pair<int,int>>v;
                for(int i=0;i<n;i++){
                      v.push_back({nums[i],i});
                }
               
                sort(v.begin(),v.end());

                for(int i=0;i<n-1;i++){
                         int u1=v[i].first;
                         int u2=v[i+1].first;

                         if(abs(u1-u2)<=limit){
                              ds.unionBysize(v[i].second,v[i+1].second);
                         }
                }

                unordered_map<int,vector<int>>c;

                for(int i=0;i<n;i++){
                        
                        int root=ds.findUpar(i);
                        c[root].push_back(i);
    
                }

                 vector<int>used(n,0);
                 vector<int>ans=nums;

                  for(auto it:c){
                       
                       vector<int>temp=it.second;
                       vector<int>val;
                       for(auto idx:temp){
                              val.push_back(nums[idx]);
                       }

                       sort(val.begin(),val.end());

                       for(int i=0;i<temp.size();i++){
                               ans[temp[i]]=val[i];
                       }

                  }

                return ans;


    }
};