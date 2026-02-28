class Solution {
public:

int factorial(int n){
        
        if(n==0||n==1)return 1;
         
        int fact=1; 
        for(int i=1;i<=n;i++){
             fact=fact*i;
        }
        return fact;
}
    bool isDigitorialPermutation(int n) {
            
            string s=to_string(n);
            sort(s.begin(),s.end());
            int x=stoi(s);

            int ans=0;
            for(int i=0;i<s.size();i++)
            {
                   int fact=factorial(s[i]-'0');
                   ans+=fact;
            }
            string req=to_string(ans);

           if(s.size()!=req.size())return false;

             vector<int>v1(10,0),v2(10,0);
             for(auto it:s){
                   v1[it-'0']++;
             }
             for(auto it:req){
                   v2[it-'0']++;
             }

             for(int i=0;i<10;i++)
             {
                  if(v1[i]!=v2[i])return false;
             }

             return true;

             


    }
};