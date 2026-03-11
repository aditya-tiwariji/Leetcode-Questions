class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
               
                  vector<int>v;
                 int n=s.size();
                  for(int i=0;i<s.size();i++){
                          if(s[i]==c){
                                v.push_back(i);
                          }
                  }

                  vector<int>ans;

                  for(int i=0;i<v.size();i++)
                  {
                          if(i==0){
                            for(int j=0;j<=v[i];j++)
                            {
                               ans.push_back(abs(v[i]-j));
                                    
                            }
                            if(i==v.size()-1){
                                  for(int k=v[i]+1;k<n;k++){
                                      ans.push_back(abs(v[i]-k));
                                  }

                                  return ans;
                            }
                         }
                            else{
                                  
                                     
                                           
                                              int mid=(v[i-1]+v[i])/2;

                                              for(int k=v[i-1]+1;k<=mid;k++)
                                              {
                                                    ans.push_back(abs(v[i-1]-k));
                                              }

                                              for(int k=mid+1;k<=v[i];k++)
                                              {
                                                  ans.push_back(abs(v[i]-k));
                                              }

                                              if(i==v.size()-1){
                                  for(int k=v[i]+1;k<n;k++){
                                      ans.push_back(abs(v[i]-k));
                                  }

                                  return ans;
                            }
                                     
                            }
                  }

                  return ans;
    }
};