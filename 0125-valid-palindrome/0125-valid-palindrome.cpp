class Solution {
public:
    bool isPalindrome(string s) {
            
            if(s=="")return true;

            int n=s.size();
            string ans=""; 
            for(int i=0;i<n;i++)
            {
                   
                   int val=s[i];
                   if((val>=65&&val<=90)||(val>=97&&val<=122)||(s[i]>='0'&&s[i]<='9')){
                          s[i]=tolower(s[i]);
                          ans+=s[i];
                   }
            }

            string p=ans;

            reverse(ans.begin(),ans.end());

            if(ans==p)return true;
            return false;
    }
}; 