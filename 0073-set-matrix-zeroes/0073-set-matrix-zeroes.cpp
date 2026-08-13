class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
           
            int n=matrix.size();// no of rows
            int m=matrix[0].size();// no of col

            vector<int>row(n,0),col(m,0);

            for(int i=0;i<n;i++)// O(n)
            {
                for(int j=0;j<m;j++)//O(m)
                {
                       if(matrix[i][j]==0){
                               row[i]=1;
                               col[j]=1;

                       }
                }
            }

            for(int i=0;i<n;i++)//O(n)
            {
                  if(row[i]==1){
                      for(int j=0;j<m;j++){//O(m)
                           matrix[i][j]=0;
                      }
                  }
            }

            for(int j=0;j<m;j++)//O(m)
            {
                  if(col[j]==1){
                       for(int i=0;i<n;i++){//O(n)
                            matrix[i][j]=0;
                       }
                  }
            }

            // total tc-->O(n*m)
            // sc-->O(1)



    }
};