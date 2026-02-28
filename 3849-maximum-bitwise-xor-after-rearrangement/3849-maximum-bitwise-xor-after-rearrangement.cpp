class Solution {
public:
    string maximumXor(string s, string t) {
             
                int cnt1=count(t.begin(),t.end(),'1');
                int cnt0=count(t.begin(),t.end(),'0');

                string ans="";
                for(int i=0;i<s.size();i++)
                {
                      if(s[i]=='1'){
                           if(cnt0>0){
                                 ans+='1';
                                 cnt0--;
                           }
                           else{
                              ans+='0';
                              cnt1--;
                           }
                      }
                      else{
                           if(cnt1>0){
                               ans+='1';
                               cnt1--;
                           }
                           else{
                              ans+='0';
                              cnt0--;
                           }
                      }
                }

                return ans;
    }
};