class Solution {
public:
    char findKthBit(int n, int k) {
            
               string s="0";

               for(int i=1;i<=n;i++)
               {
                    string p=s;

                    for(int j=0;j<p.size();j++)
                    {
                          if(p[j]=='0')p[j]='1';
                          else p[j]='0';
                        
                        
                    }
                      reverse(p.begin(),p.end());
                        s+='1'+p;
               }

             return s[k-1];


    }
};