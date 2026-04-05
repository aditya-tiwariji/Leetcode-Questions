class Solution {
public:
    int mirrorFrequency(string s) {
           int n=s.size();

           unordered_set<char>seen(s.begin(),s.end());
           unordered_map<char,int>mpp;

           for(int i=0;i<n;i++)
           {
                 mpp[char(s[i])]++;
           }
           int cnt=0;
           for(char ch='a';ch<='z';ch++)
           {
              
                   int fc=mpp[ch];
                   char m='z'+'a'-ch;
                   if(ch>m)break;
                   int fm=mpp[m];

                   cnt+=abs(fc-fm);  
              
              
           }

           for(int i=0;i<=9;i++)
           {
               char ch='0'+i;
                char m='0'+9-i;
                if(ch>m)break;
                cnt+=abs(mpp[ch]-mpp[m]);
           }

           return cnt;
    } 
};