class Solution {
public:
    bool checkOnesSegment(string s) {
          
               int n=s.size();
               int cnt=0;  
               for(int i=0;i<n;i++)
               {
                   if(s[i]=='0')continue;

                    int j=i;
                    
                    while(j<n&&s[j]=='1'){
                         j++;  
                    }
                    if(j-i>=1){
                         cnt++;
                    }

                    i=j-1;

               }

               if(cnt==1)return true;
               return false;
    }
};