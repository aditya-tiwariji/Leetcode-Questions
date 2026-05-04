class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n=matrix.size();
        
        // transpose nikala

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                 swap(matrix[i][j],matrix[j][i]);
            }
        }

        //REVERSE KIYA har ek row ko

        for(int i=0;i<n;i++){
            // ROW REVERSE HO JAYEGA 
             reverse(matrix[i].begin(),matrix[i].end());
        }

        
    }
};