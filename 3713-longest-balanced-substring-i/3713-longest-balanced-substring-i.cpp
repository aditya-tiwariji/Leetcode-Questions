class Solution {
public:
    int longestBalanced(string s) {
          int n=s.size();
           
           
int maxi=0;
          for(int i=0;i<n;i++){

             unordered_map<char,int>mpp;
             for(int j=i;j<n;j++)
             {
                     mpp[s[j]]++;
                     int freq=mpp[s[j]];
                     bool f=true;
                    for(char ch='a';ch<='z';ch++)
                    {
                           if(mpp.find(ch)!=mpp.end()&&mpp[ch]!=freq){
                                f=false;
                                break;
                           }
                    }

                    if(f){
                         maxi=max(maxi,j-i+1);
                    }
             }
          }
     
     return maxi;

    }
};