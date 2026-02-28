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

            if(s==req)return true;
            while(true){
                   bool f=next_permutation(s.begin(),s.end());
                   if(!f)return false;
                   if(s==req)return true;
                   
            }
            return false;
    }
};