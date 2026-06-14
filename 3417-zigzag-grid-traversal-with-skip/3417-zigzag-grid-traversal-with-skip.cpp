class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
                   int n=grid.size();
                   int m=grid[0].size();

                   int i=0;
                   int j=0;

                   vector<int>ans;
              
                   for(int i=0;i<n;i++){
                      int j=0;
                       if(m%2&&i%2)j++;
                       for(;j<m;j+=2){
                           if(i%2==0){
                                ans.push_back(grid[i][j]);
                           }
                           else{
                               
                                ans.push_back(grid[i][m-1-j]);
                           }
                       }
                   }
                   return ans;


                   
    }
};