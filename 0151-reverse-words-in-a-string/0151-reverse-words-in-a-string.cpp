class Solution {
public:
    string reverseWords(string s) {
             int n=s.length();
           
           string ans="";
           
           for(int i=n-1;i>=0;)
           {
                  
                   while(i>=0&&s[i]==' '){
                         i--;
                   }
                   
                   string p="";
                   
                   while(i>=0&&s[i]!=' '){
                          p=s[i]+p;
                          i--;
                   }
                   if(p=="")break;
                   
                   ans+=p+' ';
                   
                  
           }
           
            ans.pop_back();
            
            return ans;
    }
};