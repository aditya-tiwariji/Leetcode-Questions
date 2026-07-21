class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
           
              int one=count(s.begin(),s.end(),'1');

               int cntzl=0;
               int cntzr=0;
               int cnt1=0;

            s="1"+s;
            s=s+"1";

              int n=s.length();
              int ans=0;
              int b=0;
              int k=one;
              for(int i=0;i<n;i++)
              {
                       int j=i;
                       if(b==0){
                       while(j<n&&s[j]!='0'){
                             j++;
                         
                             b=1;
                       }
                      }
                        
                         while(j<n&&s[j]=='0'){
                              cntzl++;
                              j++;
                         }

                         while(j<n&&s[j]=='1'){
                              cnt1++;
                              j++;
                         } 

                         while(j<n&&s[j]=='0'){
                              cntzr++;
                              j++;
                         }

                         if(cntzl>0&&cntzr>0&&cnt1>0){
                        
                            int sum=cntzr+cnt1+cntzl+one-cnt1;
                              ans=max(ans,sum);
                              cntzl=cntzr;
                              cntzr=0;
                              cnt1=0;
                         }

                         i=j;
                         i--;


              }

             
              return max(ans,one);

             // tc==O(n)
             // sc==O(1)
    }
};