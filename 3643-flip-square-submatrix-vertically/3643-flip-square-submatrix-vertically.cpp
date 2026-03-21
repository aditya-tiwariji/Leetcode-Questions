class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
            int i=x;
            int j=x+k-1;

             while(i<j)
             {
                  for(int col=y;col<=y+k-1;col++){
                    int a=grid[i][col];
                    int b=grid[j][col];
                         grid[i][col]=b;
                         grid[j][col]=a; 
                  }
                  i++;
                  j--;
             }

             return grid;
    }
};