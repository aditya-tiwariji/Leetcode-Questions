class Solution {
public:
    string smallestPalindrome(string s) {
        
           unordered_map<char,int>mpp;

           for(auto it:s)mpp[it]++;

           char c='$';
           for(auto it:mpp){
              if(it.second%2){
                  c=it.first;
                  break;
              }
           }

           string ans="";
           int k=mpp.size();
          
         
           for(char ch='a';ch<='z';ch++){
               if(!mpp[ch]){
                  continue;
               }

               int len=mpp[ch];
              

               for(int i=1;i<=len/2;i++){
                      ans+=ch;
                      mpp[ch]--;
               }
               k--;

               if(k==0){
                
                    break;
               }

           }


         if(c!='$'){  
            ans+=c;
            mpp[c]--;
         }

        int j;
        if(c=='$')j=ans.length()-1;
        else j=ans.length()-2;

         for(int i=j;i>=0;i--){
                
               if(mpp[ans[i]]){
                   ans+=ans[i];
                   mpp[ans[i]]--;
               }
         } 

           return ans;


    }
};