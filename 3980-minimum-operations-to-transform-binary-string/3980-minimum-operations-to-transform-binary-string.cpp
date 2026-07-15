class Solution {
public:
    int minOperations(string s1, string s2) {
           int n=s1.size();

           if(n==1){
              if(s1[0]=='1'){
                  if(s1[0]!=s2[0])return -1;
              }
              else{
                  if(s1[0]==s2[0])return 0;
                  return 1;
              }
           }

           int cnt=0;
           for(int i=0;i<n;i++)
           {
                 if(s1[i]=='0'&&s1[i]!=s2[i]){
                       s1[i]='1';
                       cnt++;
                       continue;
                 }
                 else if(s1[i]=='1'&&s1[i]!=s2[i]){
                      
                      bool f1=0;
                      bool f2=0;

                      if(i-1>=0&&s1[i-1]=='1')f1=1;
                      if(i+1<n&&s1[i+1]=='1')f2=1;

                      if(!f1&&!f2){
                           cnt+=2;
                           s1[i]='0';
                      }
                      else{
                             
                             if(f2){
                                 s1[i]='0';
                                 s1[i+1]='0';
                                 cnt++; 
                                 continue;
                             }
                             if(f1){
                                 s1[i]='0';
                                 s1[i-1]='0';
                                 if(s2[i-1]!=s1[i-1]){
                                       cnt+=2;
                                 }
                                 else{
                                     cnt++;
                                 }
                             }

                      }
                      
                 }

               
           }
             return cnt;
    }
};