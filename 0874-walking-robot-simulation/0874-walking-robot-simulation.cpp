class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
           
               int n=commands.size();
               int m=obstacles.size();

              set<vector<int>>seen(obstacles.begin(),obstacles.end());
               
               map<char,char>right;

               right['N']='E';
               right['S']='W';
               right['E']='S';
               right['W']='N';

               map<char,char>left;

               left['N']='W';
               left['S']='E';
               left['E']='N';
               left['W']='S';

            char cur='N';
            int x=0;
            int y=0;
            int maxi=0;
            for(int i=0;i<n;i++)
            {
                   if(commands[i]==-2){
                           cur=left[cur];
                   }
                   else if(commands[i]==-1){
                        cur=right[cur];
                   }
                   else{
                        int k=commands[i];
                        if(cur=='N'){
                               for(int i=1;i<=k;i++)
                               {
                                    
                                     if(seen.count({x,y+1})){
                                           break;
                                     }
                                     y++;
                               }
                               
                             
                        }
                        else if(cur=='S'){
                               for(int i=1;i<=k;i++)
                               {
                                    
                                     if(seen.count({x,y-1})){
                                           break;
                                     }
                                     y--;
                               }
                             
                        }
                        else if(cur=='E'){
                                 for(int i=1;i<=k;i++)
                               {
                                    
                                     if(seen.count({x+1,y})){
                                           break;
                                     }
                                     x++;
                               }
                           
                        }
                        else if(cur=='W'){
                                for(int i=1;i<=k;i++)
                               {
                                    
                                     if(seen.count({x-1,y})){
                                           break;
                                     }
                                     x--;
                               }
                               
                            
                        }
                        int dis=x*x+y*y;
                           maxi=max(maxi,dis);
                   }
            }

            return maxi;


    }
};