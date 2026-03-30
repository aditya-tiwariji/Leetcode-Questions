class Solution {
public:
    bool checkStrings(string s1, string s2) {
               int n=s1.size();
                
                unordered_map<char,int>mpp;
                unordered_map<char,int>cpp;

                for(int i=0;i<n;i++)
                {
                       if(i%2)cpp[s1[i]]++;
                       else mpp[s1[i]]++;
                }

                for(int i=0;i<n;i++)
                {
                      if(i%2)cpp[s2[i]]--;
                      else mpp[s2[i]]--;
                }

                for(auto it:mpp)if(it.second>0)return false;
                for(auto it:cpp)if(it.second>0)return false;

                return true;
                
                


             

               
    }
};