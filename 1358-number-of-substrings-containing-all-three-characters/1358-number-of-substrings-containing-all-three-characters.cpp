class Solution {
public:
    int numberOfSubstrings(string s) {
              
                int n=s.length();

                int i=0;
                int j=0;
                
                int cnta=0,cntb=0,cntc=0; 
                int ans=0;
                while(j<n){
                       
                         if(s[j]=='a')cnta++;
                         else if(s[j]=='b')cntb++;
                         else cntc++;

                         while(cnta>=1&&cntb>=1&&cntc>=1){
                                
                                   ans+=n-j;

                                   if(s[i]=='a')cnta--;
                                   else if(s[i]=='b')cntb--;
                                   else cntc--;

                                   i++;

                         }

                         j++;
                }

                return ans;
    }
};