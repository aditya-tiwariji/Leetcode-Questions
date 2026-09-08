class Solution {
public:
vector<vector<int>>dir={{-2,-1},{-2,1},{-1,2},{-1,-2},{2,-1},{2,1},{1,2},{1,-2}};
vector<vector<vector<int>>>dp;
long long  mod=1e9+7;

int  solve(int i,int j,int n,int count,vector<vector<int>>&v){
          if(count==n){
              return 1;
          }

          if(dp[i][j][count]!=-1)return dp[i][j][count];

             long long  cnt=0;
             for(auto &it: dir){
                 int ni=i+it[0];
                 int nj=j+it[1];

                if(ni<0||ni>=4||nj<0||nj>=3||v[ni][nj]==-1)continue;

                cnt=(cnt+solve(ni,nj,n,count+1,v))%mod;


             }

             return dp[i][j][count]=cnt%mod;
}
    int knightDialer(int n) {
        

           vector<vector<int>>v(4,vector<int>(3,-1));

          int k=1;
           for(int i=0;i<3;i++){
             for(int j=0;j<3;j++)
             {
                  v[i][j]=k;
                  k++;

             }
           }
          
            v[3][1]=0;
          
          dp.assign(4,vector<vector<int>>(3,vector<int>(5000+1,-1)));
         int ans=0;
           for(int i=0;i<3;i++){
              for(int j=0;j<3;j++){
                    
               ans=(ans+solve(i,j,n,1,v))%mod;
              }
           }
           
         ans=(ans+solve(3,1,n,1,v))%mod;

           return ans%mod;
                 
           
    }
};
