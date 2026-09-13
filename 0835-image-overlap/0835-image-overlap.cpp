class Solution {
public:
int Overlap(vector<vector<int>>& A, vector<vector<int>>& B,int rowOffset,int colOffset){
               int n=A.size();
                int count=0;

                for(int i=0;i<n;i++)
                {
                      for(int j=0;j<n;j++)
                      {
                              int ni=i+rowOffset;
                              int nj=j+colOffset;

                              if(ni<0||ni>=n||nj<0||nj>=n)continue;

                              if(A[i][j]==1&&B[ni][nj]==1){
                                   count++;
                              }
                      }
                }

                return count;
}
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        
             int n=A.size();
             int maxi=0;
            for(int rowOffset=-n+1;rowOffset<n;rowOffset++)
            {
                  for(int colOffset=-n+1;colOffset<n;colOffset++)
                  {
                            int cnt=Overlap(A,B,rowOffset,colOffset);

                            maxi=max(maxi,cnt);
                  }
            }

            return maxi;
    }
};