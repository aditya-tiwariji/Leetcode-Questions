class Solution {
public:
long long   MOD=1e9+7;
    int concatenatedBinary(int n) {
           
               string ans="";
               for(int i=1;i<=n;i++)
               {
                    string s=bitset<32>(i).to_string();
                    s=s.substr(s.find('1'));
                    ans+=s;
               }
              
              int x=0;
               for(auto ch:ans){
                    x=(x*2+(ch-'0'))%MOD;
               }

               return x;
    }
};