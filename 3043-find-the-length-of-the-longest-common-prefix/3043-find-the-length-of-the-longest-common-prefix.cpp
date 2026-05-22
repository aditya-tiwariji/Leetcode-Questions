class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
            long long  n=arr1.size();
            long long  m=arr2.size();

            
             unordered_set<string>seen;  
            for(long long  i=0;i<n;i++)
            {    
                   string a=to_string(arr1[i]);
                      
                   string sub="";   
                   for(int j=0;j<a.size();j++)
                   {
                          sub+=a[j];
                          seen.insert(sub);
                   }
                
            }

            int maxi=0;

            for(int i=0;i<m;i++){
                 string b=to_string(arr2[i]);

                 string sub="";
                 for(int j=0;j<b.size();j++)
                 {
                       sub+=b[j];
                       if(seen.count(sub)){
                           maxi=max(maxi,(int)sub.length());
                       }
                 }
            }

            return maxi;

    }
};