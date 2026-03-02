class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
                 int n=grid.size();
                 int m=grid[0].size();

                 vector<int>end_Zeros(n,0);

                 for(int i=0;i<n;i++)
                 {
                       int cnt=0;
                       for(int j=m-1;j>=0;j--)
                       {
                            if(grid[i][j]==0)cnt++;
                            else break;
                       }
                       end_Zeros[i]=cnt;
                 }

                 int ans=0;
                 for(int i=0;i<n;i++)
                 {
                        int need=n-i-1;
                        if(end_Zeros[i]>=need)continue;

                        bool f=false;
                        for(int j=i+1;j<n;j++)
                        {
                               if(end_Zeros[j]>=need){
                                     ans+=j-i;

                                    while(j>i){ 
                                     swap(end_Zeros[j],end_Zeros[j-1]);
                                     j--;
                                    }
                                     f=true;
                                     break;
                               }
                        }

                        if(!f)return -1;
                 }

                 return ans;

    }
};