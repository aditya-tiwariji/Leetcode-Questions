class Solution {
public:
    int countSubstrings(string s) {
           
           int n=s.size();

             int ans=0;
             for(int k=0;k<n;k++)
             {
                    
                    // for odd length

                    int i=k;
                    int j=k;
                    int cnt=0;
                    while(i>=0&&j<n&&s[i]==s[j]){
                          i--;
                          j++;
                          cnt++;
                    }


                    // for even length

                     i=k;
                     j=k+1;
                    int cnt2=0;
                    while(i>=0&&j<n&&s[i]==s[j]){
                           i--;
                           j++;
                           cnt++;
                    }

                    ans+=max(cnt,cnt2);
             }  

             return ans;

    }
};