class Solution {
public:
 vector<vector<int>>dir={{0,-1},{-1,0},{1,0},{0,1}};

 using piii=pair<int,pair<int,int>>;

    int minimumEffortPath(vector<vector<int>>& heights) {
             int n=heights.size();
             int m=heights[0].size();

            vector<vector<int>>minEff(n,vector<int>(m,1e9));

           priority_queue<piii, vector<piii>, greater<piii>>pq;

           pq.push({0,{0,0}});

           while(!pq.empty()){
                   int i=pq.top().second.first;
                   int j=pq.top().second.second;

                   int effort=pq.top().first;
                   pq.pop();

                   for(auto it:dir){
                      int ni=i+it[0];
                      int nj=j+it[1];

                      if(ni>=0&&ni<n&&nj>=0&&nj<m){
                           int eff=max(effort,abs(heights[ni][nj]-heights[i][j]));
                           if(eff<minEff[ni][nj]){
                                minEff[ni][nj]=eff;
                                 pq.push({eff,{ni,nj}});
                           }
                          
                      }
                   }
           }

           return (minEff[n-1][m-1]!=1e9)?minEff[n-1][m-1]:0;
    }
};