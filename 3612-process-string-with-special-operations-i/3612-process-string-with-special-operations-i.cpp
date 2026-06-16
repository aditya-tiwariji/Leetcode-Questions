class Solution {
public:
    string processStr(string s) {
        int n=s.size();

        string res="";

        for(int i=0;i<n;i++)
            {
                if(s[i]=='*')
                {
                    if(!res.empty())
                    {
                        res.pop_back();
                    }
                }
                else if(s[i]=='#')
                {   
                    if(!res.empty()){
                        int csize=res.size();
                    for(int j=0;j<csize;j++){
                        res.push_back(res[j]);
                    }
                    }
                }
               else  if(s[i]=='%')
                {
                    reverse(res.begin(),res.end());
                }
                else{
                     res.push_back(s[i]);
                }
            }

        return res;
    }
};