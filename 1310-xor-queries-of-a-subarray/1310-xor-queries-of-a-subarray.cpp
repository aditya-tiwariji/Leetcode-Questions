class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
                   int n=arr.size();

                   vector<int>preXr(n+1,0);
                   for(int i=1;i<=n;i++){
                       preXr[i]=preXr[i-1]^arr[i-1];
                   }
                   vector<int>ans;
                   for(auto it:queries){
                       int l=it[0];
                       int r=it[1];

                       int xr=preXr[r+1]^preXr[l];
                       ans.push_back(xr);
                   }

                   return ans;
    }
};