class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
           int  n=A.size();

           vector<int>C(n,0);

            unordered_set<int>seen;
            int cnt=0;   
            for(int i=0;i<n;i++)
            {
                
                  if(seen.count(A[i])){
                        cnt++;
                      

                  }
                  else{
                      seen.insert(A[i]);
                  }
                  if(seen.count(B[i])){
                       cnt++;
                  }
                  else{
                      seen.insert(B[i]);
                  }
                  C[i]=cnt;
            }

           
           return C;
    }
};