class Solution {
public:
    long long sumAndMultiply(int n) {
           string s=to_string(n);
          string p="";
           for(int i=0;i<s.size();i++)
               {
                   if((s[i]-'0')!=0)p+=s[i];
               }
        if(p.empty())return 0;
         int  sum=0;
             for(long long  i=0;i<p.size();i++)
                 {
                     sum+=p[i]-'0';
                 }
           long long   x=stoll(p);

        return x*sum;
    }
};