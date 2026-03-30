class Solution {
public:
    bool checkStrings(string s1, string s2) {
               int n=s1.size();
               

               for(int i=0;i<n;i++)
               {
                     if(s1[i]!=s2[i]){
                           bool f=false;
                           for(int j=i+2;j<n;j+=2)
                           {
                                  if(s1[j]==s2[i]){
                                        f=true;
                                        swap(s1[i],s1[j]);
                                        break;
                                  }
                           }
                           if(!f)return false;
                     }
               }

               return true;
    }
};