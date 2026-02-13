class Solution {
public:

int fun(string s,char ch1,char ch2 ){
             
               unordered_map<int,int>mpp; // diff,index
               int cnt1=0;
               int cnt2=0;
               int ans=0;
               for(int i=0;i<s.size();i++){
                      if(s[i]==ch1)cnt1++;
                      if(s[i]==ch2)cnt2++;
            
                      if(cnt1==cnt2){
                             ans=max(ans,cnt1+cnt2);
                      }

                      if(s[i]!=ch1&&s[i]!=ch2){
                             cnt1=0;
                             cnt2=0;
                             mpp.clear();
                             continue;
                      }

                      int diff=cnt1-cnt2;
                      if(mpp.count(diff)){
                             ans=max(ans,i-mpp[diff]);
                      }
                      else{
                           mpp[diff]=i;
                      }

               }

               return ans;

}
    int longestBalanced(string s) {
           int n=s.size();
           int maxi=1;

           //case1

           int cnt=1;
           for(int i=1;i<n;i++)
           {
               if(s[i]==s[i-1]){
                    cnt++;
               }
               else{
                  maxi=max(maxi,cnt);
                  cnt=1;
               }
           }
           maxi=max(maxi,cnt);

           // case2

           int len_ab=fun(s,'a','b');
           int len_ac=fun(s,'a','c');
           int len_bc=fun(s,'b','c');

           maxi=max({maxi,len_ab,len_ac,len_bc});

           // case3

           unordered_map<string,int>diff;
           int cnta=0;
           int cntb=0;
           int cntc=0;
           diff["0_0"] = -1;

           for(int i=0;i<n;i++){
                 if(s[i]=='a')cnta++;
                 if(s[i]=='b')cntb++;
                 if(s[i]=='c')cntc++;


                 if(cnta==cntb&&cnta==cntc){
                           maxi=max(maxi,cnta+cntb+cntc);
                 }

                 int diffab=cnta-cntb;
                 int diffac=cnta-cntc;

                 string req=to_string(diffab)+'_'+to_string(diffac);

                 if(diff.count(req)>0){
                            
                              maxi=max(maxi,i-diff[req]);
                 }
                 else{
                        diff[req]=i;
                 }
           }

           return maxi;


    }  
};