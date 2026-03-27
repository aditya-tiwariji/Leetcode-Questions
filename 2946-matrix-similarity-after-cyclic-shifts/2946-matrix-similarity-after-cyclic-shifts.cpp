class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
            int n=mat.size();
            int m=mat[0].size();

             vector<vector<int>>mat2=mat;  
             k=k%m;  
           
                    for(int row=0;row<n;row++)
                    {
                        vector<int>temp=mat2[row];
                        if(row%2){
                              rotate(temp.begin(),temp.end()-k,temp.end());
                        }
                        else{
                             rotate(temp.begin(),temp.begin()+k,temp.end());
                        }
                        mat2[row]=temp;
                    }
                    
            

            if(mat2==mat)return true;
            return false;
    }
};