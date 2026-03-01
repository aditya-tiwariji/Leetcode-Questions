class Solution {
public:
    string mergeCharacters(string s, int k) {
        
             int n=s.size();

    while(true){
        bool ok=false;

             for(int i=0;i<s.size();i++)
             {
                   
                  for(int j=i+1;j<s.size();j++)
                  {
                
                        if(s[i]==s[j]&&j-i<=k){
                              s.erase(j,1);
                              ok=true;
                              break;
                        }
                  }
                if(ok)break;
             }
             if(!ok)break;
    }
             return s;
    }
};