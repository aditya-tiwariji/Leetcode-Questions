class Solution {
public:
    long long mod=1e9+7;
    int func(int i, int j, vector<vector<int>>& arr, int n, int steps, vector<vector<vector<int>>>&dp){
            if(i<0 || j<0 || i>3 || j>2 || (i==3 && (j==0 || j==2))) return 0;
            if(steps==n) return 1;
            if(dp[i][j][steps]!=-1) return dp[i][j][steps];

            long long m1=func(i+2,j-1,arr,n,steps+1,dp);
            long long m2=func(i+2,j+1,arr,n,steps+1,dp);
            long long m3=func(i-2,j-1,arr,n,steps+1,dp);
            long long m4=func(i-2,j+1,arr,n,steps+1,dp);
            long long m5=func(i-1,j+2,arr,n,steps+1,dp);
            long long m6=func(i-1,j-2,arr,n,steps+1,dp);
            long long m7=func(i+1,j+2,arr,n,steps+1,dp);
            long long m8=func(i+1,j-2,arr,n,steps+1,dp);

            return dp[i][j][steps]=(m1+m2+m3+m4+m5+m6+m7+m8)%mod;
    }

    int knightDialer(int n) {
        
        vector<vector<int>>arr(4,vector<int>(3));
        vector<vector<vector<int>>>dp(4,vector<vector<int>>(3,vector<int>(n+1,-1)));
        int cnt=1;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                arr[i][j]=cnt;
                cnt++;
            }
        }
        arr[3][0]=-1;
        arr[3][1]=0;
        arr[3][2]=-1;
        int ans=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(!(i==3 && (j==0 || j==2))){
                    ans=(ans+func(i,j,arr,n,1,dp))%mod;
                }
            }
        }
        return ans;

    }
};