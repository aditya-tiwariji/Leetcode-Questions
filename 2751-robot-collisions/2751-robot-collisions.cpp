class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
                     int n=positions.size();
                     int m=healths.size();
                     int N=directions.size();

                     map<int,pair<int,char>>mpp;

                     vector<int>nums=positions;

                     for(int i=0;i<n;i++)
                     {
                           mpp[positions[i]]={healths[i],directions[i]};     
                     }

                     sort(positions.begin(),positions.end());

                     stack<pair<int,int>>st;
                    
                    map<int,int>ans;
                     for(int i=0;i<n;i++){
                            
                           char ch=mpp[positions[i]].second;
                           int health=mpp[positions[i]].first;
                           if(ch=='R'){
                               st.push({health,positions[i]});
                           }
                           else{
                                
                                   while(!st.empty()&&st.top().first<health){
                                                   st.pop();
                                                   health--;
                                            }
                                       if(st.empty()){
                                           ans[positions[i]]=health;
                                           continue;
                                       }  

                                   if(st.top().first==health){
                                        st.pop();
                                        continue;
                                   }
                                   else{
                                         int H=st.top().first;
                                         int pos=st.top().second;
                                         st.pop();
                                         st.push({H-1,pos});
                                   }
                           }
                     }


                   while(!st.empty()){
                          int h=st.top().first;
                          int pos=st.top().second;

                          st.pop();

                          ans[pos]=h;
                                 
                   }  

                   vector<int>V;

                   for(int i=0;i<n;i++)
                   {
                        if(ans.count(nums[i])){
                               V.push_back(ans[nums[i]]);
                        }
                   } 

                   return V; 


                        
    } 
};